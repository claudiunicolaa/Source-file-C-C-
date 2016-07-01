#include "practical_exam_oop.h"

Practical_Exam_OOP::Practical_Exam_OOP(Controller& ctrl, QWidget *parent)
	: QMainWindow(parent), ctrl(ctrl)
{
	ui.setupUi(this);
	buildWindow();
	connect();
}

void Practical_Exam_OOP::buildList(std::vector<Nota> note) {
	this->list->clear();
	this->students.clear();
	for (auto it = note.begin(); it != note.end(); ++it) {
		Nota not = *it;
		QString nota = QString::fromStdString(not.getStudent()) + '|' + QString::number(not.getValoare())
			+ '|' + QString::fromStdString(not.getProfesor());
		new QListWidgetItem(nota, this->list);
		this->students.append(QString::fromStdString(not.getStudent()));
	}
}

void Practical_Exam_OOP::buildWindow() {
	this->mainLayout = new QVBoxLayout();
	this->list = new QListWidget();

	//main layout
	this->buildList(this->ctrl.getAllByValoare());
	this->mainLayout->addWidget(this->list);
	this->addOpenBtn = new QPushButton("Add");
	this->mainLayout->addWidget(this->addOpenBtn);

	//search layout
	this->searchField = new QLineEdit;
	this->searchField->setFixedWidth(180);
	this->searchField->setClearButtonEnabled(true);
	this->searchField->setPlaceholderText("Search...");
	this->buildList(this->ctrl.getAll());
	this->mainLayout->addWidget(this->searchField);

	//add layout
	this->addLayout = new QFormLayout();
	this->studentFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("Student"), this->studentFieldAdd);
	this->valoareFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("Valoare"), this->valoareFieldAdd);
	this->profesorFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("Profesor"), this->profesorFieldAdd);
	this->addBtn = new QPushButton("Adauga nota");
	this->addLayout->addWidget(this->addBtn);

	//add widget
	this->widgetAdd = new QWidget;
	this->widgetAdd->setLayout(this->addLayout);

	this->buildWidgets();
	this->centralWidget()->setLayout(mainLayout);
}

void Practical_Exam_OOP::buildWidgets() {
	//selecteaza distinct profi
	std::vector<std::string> profesori = this->ctrl.getProfesori();
	for (auto i = profesori.begin(); i != profesori.end(); i++) {
		auto p = *i;
		QWidget *prof = new ProfesorGUI(this->ctrl, p);
		prof->show();
	}
	//new profesor gui pt fiecare, trimite nume si note
	//show
}

void Practical_Exam_OOP::connect() {
	QObject::connect(addOpenBtn, &QPushButton::clicked, this, &Practical_Exam_OOP::openAddWidget);
	QObject::connect(addBtn, &QPushButton::clicked, this, &Practical_Exam_OOP::add);
	QObject::connect(searchField, &QLineEdit::textChanged, this, &Practical_Exam_OOP::search);
}

void Practical_Exam_OOP::openAddWidget() {
	this->widgetAdd->show();
}

void Practical_Exam_OOP::add() {
	std::string student = this->studentFieldAdd->text().toStdString();
	float valoare = this->valoareFieldAdd->text().toFloat();
	std::string profesor = this->profesorFieldAdd->text().toStdString();
	try {
		this->ctrl.add(student, valoare, profesor);
		this->buildList(this->ctrl.getAllByValoare());
	}
	catch (Validator &ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
	}
	this->widgetAdd->hide();
}

void Practical_Exam_OOP::search() {
	this->list->clear();
	std::vector<Nota> note = this->ctrl.getAll();
	for (auto it = note.begin(); it != note.end(); ++it) {
		Nota n = *it;
		if (QString::fromStdString(n.getStudent()).contains(this->searchField->text())) {
			QString nota = QString::fromStdString(n.getStudent()) + "|" + QString::number(n.getValoare()) + "|" + QString::fromStdString(n.getProfesor());
			new QListWidgetItem(nota, this->list);
		}
	}
}

Practical_Exam_OOP::~Practical_Exam_OOP()
{

}
