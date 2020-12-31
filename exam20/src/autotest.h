#ifndef AUTOTEST_H
#define AUTOTEST_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QtTest/QtTest>
#include <QDebug>



class autoTest : public QObject
{
    Q_OBJECT
public:
    autoTest(QObject *parent = nullptr);

signals:

private slots:
    void testAddColor();
    void testDelColor();
};

#endif // AUTOTEST_H
