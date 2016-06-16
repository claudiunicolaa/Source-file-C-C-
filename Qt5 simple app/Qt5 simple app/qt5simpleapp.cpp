#include "qt5simpleapp.h"

Qt5simpleapp::Qt5simpleapp(Controller& ctrl, QWidget *parent)
	: QMainWindow(parent), ctrl(ctrl)
{
	ui.setupUi(this);
	buildWindow();
	connect();
}

void Qt5simpleapp::buildList(std::vector<Student> students) {
	this->list->clear();
	for (auto it = students.begin(); it != students.end(); ++it) {
		Student stud = *it;
		QString student = QString::fromStdString(stud.getName()) + '|' + QString::fromStdString(stud.getUniversity())
			+ '|' + QString::number(stud.getFinalGrade());
		new QListWidgetItem(student, this->list);
	}
}

void Qt5simpleapp::buildWindow() {
	this->mainLayout = new QVBoxLayout();
	this->list = new QListWidget();

	//main layout
	this->buildList(this->ctrl.getAll());
	this->mainLayout->addWidget(this->list);
	this->addOpenBtn = new QPushButton("Add");
	this->updateOpenBtn = new QPushButton("Update");
	this->removeBtn = new QPushButton("Remove");
	this->mainLayout->addWidget(this->addOpenBtn);
	this->mainLayout->addWidget(this->updateOpenBtn);
	this->mainLayout->addWidget(this->removeBtn);


	//add layout
	this->addLayout = new QFormLayout();
	this->nameFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("Name"), this->nameFieldAdd);
	this->univeristyFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("University"), this->univeristyFieldAdd);
	this->finalGradeFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("Final Grade"), this->finalGradeFieldAdd);
	this->addBtn = new QPushButton("Add Student");
	this->addLayout->addWidget(this->addBtn);

	//add widget
	this->widgetAdd = new QWidget;
	this->widgetAdd->setLayout(this->addLayout);

	//update layout
	this->updateLayout = new QFormLayout;
	this->nameFieldUpdate = new QLineEdit;
	this->updateLayout->addRow(new QLabel("Name"), this->nameFieldUpdate);
	this->universityFieldUpdate = new QLineEdit;
	this->updateLayout->addRow(new QLabel("University"), this->universityFieldUpdate);
	this->finalGradeFieldUpdate = new QLineEdit;
	this->updateLayout->addRow(new QLabel("Final Grade"), this->finalGradeFieldUpdate);
	this->updateBtn = new QPushButton("Update Student");
	this->updateLayout->addWidget(this->updateBtn);

	//update widget
	this->widgetUpdate = new QWidget;
	this->widgetUpdate->setLayout(this->updateLayout);

	this->centralWidget()->setLayout(mainLayout);
}

void Qt5simpleapp::connect() {
	QObject::connect(addOpenBtn, &QPushButton::clicked, this, &Qt5simpleapp::openAddWidget);
	QObject::connect(updateOpenBtn, &QPushButton::clicked, this, &Qt5simpleapp::openUpdateWidget);
	QObject::connect(removeBtn, &QPushButton::clicked, this, &Qt5simpleapp::remove);

	QObject::connect(addBtn, &QPushButton::clicked, this, &Qt5simpleapp::add);
	QObject::connect(updateBtn, &QPushButton::clicked, this, &Qt5simpleapp::update);
}

void Qt5simpleapp::openAddWidget() {
	this->widgetAdd->show();
}
void Qt5simpleapp::openUpdateWidget() {
	if (this->list->selectedItems().count() > 0) {
		QStringList tokens = this->list->selectedItems()[0]->text().split("|");
		this->nameFieldUpdate->setText(tokens[0]);
		this->universityFieldUpdate->setText(tokens[1]);
		this->finalGradeFieldUpdate->setText(tokens[2]);
		this->widgetUpdate->show();
	}
	else {
		QMessageBox::critical(this, "Error", "Select an item.");
	}
}

void Qt5simpleapp::add() {
	std::string name = this->nameFieldAdd->text().toStdString();
	std::string university = this->univeristyFieldAdd->text().toStdString();
	double finalGrade = this->finalGradeFieldAdd->text().toDouble();
	try {
		this->ctrl.add(name, university, finalGrade);
		this->buildList(this->ctrl.getAll());
		this->widgetAdd->hide();
	}
	catch (Validator &ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
	}
}

void Qt5simpleapp::update() {
	QStringList tokens = this->list->selectedItems()[0]->text().split("|");
	std::string name = this->nameFieldUpdate->text().toStdString();
	std::string university = this->universityFieldUpdate->text().toStdString();
	double finalGrade = this->finalGradeFieldUpdate->text().toDouble();
	try {
		this->ctrl.update(tokens[0].toStdString(), tokens[1].toStdString(), tokens[2].toDouble(),
			name, university, finalGrade);
		this->buildList(this->ctrl.getAll());
		this->widgetUpdate->hide();
	}
	catch (Validator &ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
	}

}

void Qt5simpleapp::remove() {
	if (this->list->selectedItems().count() > 0) {
		QStringList tokens = this->list->selectedItems()[0]->text().split("|");
		try {
			this->ctrl.remove(tokens[0].toStdString(), tokens[1].toStdString(), tokens[2].toDouble());
			this->buildList(this->ctrl.getAll());
		}
		catch (Validator &ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
		}
	}
	else {
		QMessageBox::critical(this, "Error", "Select an item.");
	}
}

Qt5simpleapp::~Qt5simpleapp()
{

}
