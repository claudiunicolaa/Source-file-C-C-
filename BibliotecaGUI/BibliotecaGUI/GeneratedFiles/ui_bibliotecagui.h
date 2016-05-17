/********************************************************************************
** Form generated from reading UI file 'bibliotecagui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOTECAGUI_H
#define UI_BIBLIOTECAGUI_H

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

class Ui_BibliotecaGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BibliotecaGUIClass)
    {
        if (BibliotecaGUIClass->objectName().isEmpty())
            BibliotecaGUIClass->setObjectName(QStringLiteral("BibliotecaGUIClass"));
        BibliotecaGUIClass->resize(600, 400);
        menuBar = new QMenuBar(BibliotecaGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        BibliotecaGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BibliotecaGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BibliotecaGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(BibliotecaGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BibliotecaGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BibliotecaGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BibliotecaGUIClass->setStatusBar(statusBar);

        retranslateUi(BibliotecaGUIClass);

        QMetaObject::connectSlotsByName(BibliotecaGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *BibliotecaGUIClass)
    {
        BibliotecaGUIClass->setWindowTitle(QApplication::translate("BibliotecaGUIClass", "BibliotecaGUI", 0));
    } // retranslateUi

};

namespace Ui {
    class BibliotecaGUIClass: public Ui_BibliotecaGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOTECAGUI_H
