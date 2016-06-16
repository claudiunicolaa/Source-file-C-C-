#ifndef QT5SIMPLEAPP_H
#define QT5SIMPLEAPP_H

#include <QtWidgets/QMainWindow>
#include <qboxlayout.h>
#include <qlistwidget.h>
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qwidget.h>
#include <qmessagebox.h>
#include "ui_qt5simpleapp.h"
#include "Controller.h"

class Qt5simpleapp : public QMainWindow
{
	Q_OBJECT

public:
	Qt5simpleapp(Controller& ctrl, QWidget *parent = 0);
	void buildList(std::vector<Student>);
	void buildWindow();
	void connect();
	void openAddWidget();
	void openUpdateWidget();
	void remove();
	void add();
	void update();

	~Qt5simpleapp();

private:
	Ui::Qt5simpleappClass ui;
	Controller& ctrl;
	QVBoxLayout* mainLayout;
	QListWidget *list;
	QFormLayout *addLayout, *updateLayout;
	QPushButton *addOpenBtn, *addBtn, *updateOpenBtn, *updateBtn, *removeBtn;
	QLineEdit *nameFieldAdd, *univeristyFieldAdd, *finalGradeFieldAdd,
		*nameFieldUpdate, *universityFieldUpdate, *finalGradeFieldUpdate;
	QWidget *widgetAdd, *widgetUpdate;
};

#endif // QT5SIMPLEAPP_H
