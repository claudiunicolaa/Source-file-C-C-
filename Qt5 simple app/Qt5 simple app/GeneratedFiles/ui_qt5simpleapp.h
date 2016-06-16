/********************************************************************************
** Form generated from reading UI file 'qt5simpleapp.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT5SIMPLEAPP_H
#define UI_QT5SIMPLEAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt5simpleappClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt5simpleappClass)
    {
        if (Qt5simpleappClass->objectName().isEmpty())
            Qt5simpleappClass->setObjectName(QStringLiteral("Qt5simpleappClass"));
        Qt5simpleappClass->resize(600, 400);
        menuBar = new QMenuBar(Qt5simpleappClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Qt5simpleappClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt5simpleappClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Qt5simpleappClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Qt5simpleappClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Qt5simpleappClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Qt5simpleappClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Qt5simpleappClass->setStatusBar(statusBar);

        retranslateUi(Qt5simpleappClass);

        QMetaObject::connectSlotsByName(Qt5simpleappClass);
    } // setupUi

    void retranslateUi(QMainWindow *Qt5simpleappClass)
    {
        Qt5simpleappClass->setWindowTitle(QApplication::translate("Qt5simpleappClass", "Qt5simpleapp", 0));
    } // retranslateUi

};

namespace Ui {
    class Qt5simpleappClass: public Ui_Qt5simpleappClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT5SIMPLEAPP_H
