/********************************************************************************
** Form generated from reading UI file 'practical_exam_oop.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICAL_EXAM_OOP_H
#define UI_PRACTICAL_EXAM_OOP_H

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

class Ui_Practical_Exam_OOPClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Practical_Exam_OOPClass)
    {
        if (Practical_Exam_OOPClass->objectName().isEmpty())
            Practical_Exam_OOPClass->setObjectName(QStringLiteral("Practical_Exam_OOPClass"));
        Practical_Exam_OOPClass->resize(600, 400);
        menuBar = new QMenuBar(Practical_Exam_OOPClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Practical_Exam_OOPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Practical_Exam_OOPClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Practical_Exam_OOPClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Practical_Exam_OOPClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Practical_Exam_OOPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Practical_Exam_OOPClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Practical_Exam_OOPClass->setStatusBar(statusBar);

        retranslateUi(Practical_Exam_OOPClass);

        QMetaObject::connectSlotsByName(Practical_Exam_OOPClass);
    } // setupUi

    void retranslateUi(QMainWindow *Practical_Exam_OOPClass)
    {
        Practical_Exam_OOPClass->setWindowTitle(QApplication::translate("Practical_Exam_OOPClass", "Practical_Exam_OOP", 0));
    } // retranslateUi

};

namespace Ui {
    class Practical_Exam_OOPClass: public Ui_Practical_Exam_OOPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICAL_EXAM_OOP_H
