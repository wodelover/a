#include "mainwindow.h"
#include <QApplication>
#include "autotest.h"

/**
 * 编写一个颜色列表程序，功能及要求如下：
 * 
 * - 实现的功能是：添加、删除颜色项。
 * - 颜色列表继承QListView，不许使用QListWidget。数据Model继承QAbstractItemModel。
 * - 界面上有这几个元素（如何布局不做强制要求）：
 *   - 颜色列表控件：按行显示每个颜色条目。每个条目显示添加时指定的颜色。
 *   - 一个QComboBox，可以下拉选择这几种颜色：red, green, blue, cyan, yellow, purple, white, black
 *   - 一个QPushButton实现’添加‘新的颜色项。添加QComboBox当前的颜色到列表中。
 *   - 一个QPushButton实现’删除‘选择的颜色项。如果没有选择一个列表中的项，disabled状态
 */

QTEST_MAIN(autoTest)
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}
