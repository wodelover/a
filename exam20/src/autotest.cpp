#include "autotest.h"

#include "QDebug"

autoTest::autoTest(QObject *parent) : QObject(parent)
{

}

//添加颜色
void autoTest::testAddColor()
{
    MainWindow w;
//    qDebug() << w.ui->comboBox->count();
    for (int i = 0; i < w.ui->comboBox->count(); i++) {

        w.ui->comboBox->setCurrentIndex(i);
        QTest::mouseClick(w.ui->btnAdd, Qt::LeftButton);

        Qt::GlobalColor c = static_cast<Qt::GlobalColor>(w.m_Model->data(w.m_Model->index(i,0), Qt::BackgroundColorRole).toInt());

        switch(c){
        case Qt::GlobalColor::red:
            QCOMPARE("red", w.ui->comboBox->currentText());
            break;
        case Qt::GlobalColor::black:
            QCOMPARE("black", w.ui->comboBox->currentText());
            break;
        case Qt::GlobalColor::white:
            QCOMPARE("white", w.ui->comboBox->currentText());
            break;
        case Qt::GlobalColor::darkBlue:
            QCOMPARE("purple", w.ui->comboBox->currentText());
            break;
        case Qt::GlobalColor::yellow:
            QCOMPARE("yellow", w.ui->comboBox->currentText());
            break;
        case Qt::GlobalColor::cyan:
            QCOMPARE("cyan", w.ui->comboBox->currentText());
            break;
        case Qt::GlobalColor::blue:
            QCOMPARE("blue", w.ui->comboBox->currentText());
            break;
        case Qt::GlobalColor::green:
            QCOMPARE("green", w.ui->comboBox->currentText());
            break;
        }

    }
}

// 删除颜色
void autoTest::testDelColor()
{
    MainWindow w;
    for (int i = 0; i < w.ui->comboBox->count(); i++) {
        w.ui->comboBox->setCurrentIndex(i);
        QTest::mouseClick(w.ui->btnAdd, Qt::LeftButton);
    }

    QList<Qt::GlobalColor> blist;
    for (int j = 0; j < w.m_Model->rowCount(); j++) {
        Qt::GlobalColor blc = static_cast<Qt::GlobalColor>(w.m_Model->data(w.m_Model->index(j,0), Qt::BackgroundColorRole).toInt());
        blist << blc;
    }

    int beforeCount = blist.count();
    QRect rect = w.m_ListView->visualRect(w.m_Model->index(5, 0));
    QTest::mouseClick(w.m_ListView->viewport(), Qt::LeftButton, Qt::KeyboardModifiers(), rect.center());

    Qt::GlobalColor c = static_cast<Qt::GlobalColor>(w.m_Model->data(w.m_ListView->currentIndex(), Qt::BackgroundColorRole).toInt());

    QTest::mouseClick(w.ui->btnDelete, Qt::LeftButton);
    int afterCount = w.m_Model->rowCount();

    QList<Qt::GlobalColor> alist;

    for (int k = 0; k < afterCount; k++) {
        Qt::GlobalColor alc = static_cast<Qt::GlobalColor>(w.m_Model->data(w.m_Model->index(k,0), Qt::BackgroundColorRole).toInt());
        alist << alc;
    }

    QCOMPARE(afterCount, beforeCount - 1);

    for (int l = 0; l < blist.count(); l++) {
        if(alist.indexOf(blist.at(l)) == -1) {
            QCOMPARE(c, blist.at(l));
            break;
        }
    }
}
