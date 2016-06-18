#ifndef PRACTICAL_EXAM_OOP_H
#define PRACTICAL_EXAM_OOP_H

#include <QtWidgets/QMainWindow>
#include "ui_practical_exam_oop.h"
#include <qboxlayout.h>
#include <qlistwidget.h>
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qwidget.h>
#include <qmessagebox.h>
#include "Controller.h"
#include "ProfesorGUI.h"

class Practical_Exam_OOP : public QMainWindow
{
	Q_OBJECT

public:
	Practical_Exam_OOP(Controller& ctrl ,QWidget *parent = 0);
	void buildList(std::vector<Nota>);
	void buildWindow();
	void connect();
	void openAddWidget();
	void add();
	void search();
	void buildWidgets();
	~Practical_Exam_OOP();

private:
	Ui::Practical_Exam_OOPClass ui;
	Controller& ctrl;
	QVBoxLayout* mainLayout;
	QListWidget *list;
	QFormLayout *addLayout;
	QPushButton *addOpenBtn, *addBtn;
	QLineEdit *studentFieldAdd, *valoareFieldAdd, *profesorFieldAdd, *searchField;
	QWidget *widgetAdd;
	QStringList students;
	QWidgetList *profesori;
};

#endif // PRACTICAL_EXAM_OOP_H
