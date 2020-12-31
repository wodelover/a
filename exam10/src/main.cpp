#include "exam.h"
#include <QString>
/**
 * 
 * -------------------------------------------------------------------------------------------------------------------
 * 题目
 * -------------------------------------------------------------------------------------------------------------------
 * 
 * 遵循 https://specifications.freedesktop.org/desktop-entry-spec/latest/ 标准实现一个desktop文件解析工具
 * 
 * 功能要求
 * - desktop文件格式无错误时进程退出码为0
 * - 实现对desktop文件Name(程序名称)、Exec(可执行文件)、Icon(图标文件)三个字段的解析
 * - 需要检测文件的格式，遇到错误时以退出码 1 退出进程
 * - 输入接收一个desktop文件的绝对路径，能够输出程序名称、图标文件（图标文件不考虑从系统图标主题中查找）
 * - 能够在指定一个desktop文件后启动进程，且允许为其指定参数
 * 
 * 其它要求
 * - 使用cmake构建工程
 * - 可执行文件位置和名称为：./src/freedesktop
 * 
 * 示例
 * - a.desktop文件内容为:
 *     [Desktop Entry]
 *     Name=A;
 *     Name[zh_CN]="我是A";
 *     Exec=cat %f
 *     Icon=/tmp/a.png
 * 
 * - 输入参数（-d指定desktop文件的绝对路径，-n表示要获取应用程序名称）：
 *     freedesktop -d /home/a/a.desktop -n
 * - 输出结果：
 *     A或我是A（中文环境下，注意应该去掉引号）
 * 
 * - 输入参数（-i表示要获取应用程序的图标）
 *     freedesktop -d /home/a/a.desktop -i
 * - 输出结果（如图标数据不是一个文件路径，则先将图标文件保存为文件后再返回此文件的绝对路径）：
 *     /tmp/a.png
 * 
 * - 输入参数（-e表示要启动此应用程序，其后可根一个或多个传入参数）
 *     freedesktop -d /home/a/a.desktop -e /home/a/test.txt
 * - 输出结果：
 *     输出结果为 /home/a/test.txt 文件的内容，也就是Exec命令执行时对标准输出通道所写入的全部数据
 * 
 */



#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <QLocale>
#include <QSettings>
#include <QFile>
#include <QProcess>
#include <QDebug>

#include <DDesktopEntry>
#include <QFileInfo>
#include <iostream>
#include <vector>
DWIDGET_USE_NAMESPACE
DCORE_USE_NAMESPACE
using namespace std;

int main(int argc, char *argv[])
{
    QString localPath;
    QVector <QString> vec;
    QMap <QString ,QString >map;
    for(int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-d") == 0){
            if(i+1<argc){
                localPath=argv[i+1];
            }
        }
    }
    QFileInfo file(localPath);
    if(!file.exists()) return 1;
    if( file.suffix()!="desktop"){
        return 1;
    };
    DDesktopEntry desktop(localPath);  //指定需要解析的 desktop 文件名

    for(int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-n") == 0){
            QString name =desktop.name();
            if(name.contains("\"")){
               QString tmp;
              for(int i=0;i<name.size();i++)
              {
                  if(i!=0 &&i!=(name.size()-1))
                      tmp+=name[i];
              }
              name=tmp;
            };
            if(!name.isNull()){
                cout <<name.toStdString();
            }else {
                return 1;
            }
        }
        if (strcmp(argv[i], "-i") == 0){
            QString IconPath = desktop.stringValue("Icon");
            if(!IconPath.isNull()){
                cout <<IconPath.toStdString().c_str();
            }else {
                return 1;
            }

        }
        QVector<QString > vector1;
        QString deepinVendor;
        if (strcmp(argv[i], "-e") == 0){
            while((i+1)<argc){
                QString Exec = desktop.stringValue("Exec");
                QFileInfo file(argv[i+1]);
                if(Exec.isNull() ||!Exec.contains("cat"))
                {
                   return 1;
                }
                if(file.isReadable())
                {
                    vector1.push_back(argv[i+1]);
                }else {
                    break;
                }
                i++;
            }
           for(QString str:vector1)
           {
               QProcess p;
               p.start("cat "+str);
               p.waitForFinished();
              p.readAllStandardError();
              string s1=p.readAllStandardOutput().toStdString();
              string s2=p.readAllStandardError().toStdString();
              std::cout<<s1;
              std::cout<<s2;
           }
        }
    }



    return 0;
}

