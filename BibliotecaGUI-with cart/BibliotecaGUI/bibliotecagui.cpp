#include "bibliotecagui.h"

BibliotecaGUI::BibliotecaGUI(BookstoreController& ctrl, QWidget *parent)
	: QMainWindow(parent), ctrl(ctrl)
{
	ui.setupUi(this);
	buildWindow();
	connect();
}

void BibliotecaGUI::buildList(std::vector<Book> books) {
	this->list->clear();
	int c = this->list->count();
	this->titlesList.clear();
	for (auto it = books.begin(); it != books.end(); ++it) {
		Book b = *it;
		QString book = QString::number(b.getId()) + "|" + QString::fromStdString(b.getTitle()) + "|" + QString::fromStdString(b.getAuthor()) + "|" + QString::number(b.getYear()) + "|" + QString::fromStdString(b.getSubject());
		new QListWidgetItem(book, this->list);
		this->titlesList.append(QString::fromStdString(b.getTitle()));
	}
}

void BibliotecaGUI::buildWindow() {
	this->mainLayout = new QVBoxLayout();
	QHBoxLayout *top = new QHBoxLayout();
	this->list = new QListWidget();
	//search layout
	this->searchField = new QLineEdit;
	this->searchField->setFixedWidth(180);
	this->searchField->setClearButtonEnabled(true);
	this->searchField->setPlaceholderText("Search...");
	this->buildList(this->ctrl.getAll());
	QCompleter *completer = new QCompleter(this->titlesList);
	completer->setCaseSensitivity(Qt::CaseInsensitive);
	searchField->setCompleter(completer);
	this->mainLayout->addWidget(this->searchField);


	//add layout
	this->addLayout = new QFormLayout;
	this->titleFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("Title"), this->titleFieldAdd);
	this->authorFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("Author"), this->authorFieldAdd);
	this->yearFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("Year"), this->yearFieldAdd);
	this->subjectFieldAdd = new QLineEdit;
	this->addLayout->addRow(new QLabel("Subject"), this->subjectFieldAdd);
	this->widgetAdd = new QWidget;
	this->widgetAdd->setWindowTitle("Add Book");
	this->store = new QPushButton("&Store");
	this->addLayout->addWidget(this->store);
	this->widgetAdd->setLayout(this->addLayout);

	this->filterByTitleBtn = new QPushButton("Filter by title");
	this->filterByTitleBtn->setFixedSize(90, 40);
	this->mainLayout->addWidget(this->filterByTitleBtn);


	this->filterByYearBtn = new QPushButton("Filter by year");
	this->filterByYearBtn->setFixedSize(90, 40);
	this->mainLayout->addWidget(this->filterByYearBtn);

	this->sortByTitleBtn = new QPushButton("Sort by title");
	this->sortByTitleBtn->setFixedSize(160, 40);
	this->mainLayout->addWidget(this->sortByTitleBtn);

	this->sortByAuthorBtn = new QPushButton("Sort by author");
	this->sortByAuthorBtn->setFixedSize(160, 40);
	this->mainLayout->addWidget(this->sortByAuthorBtn);

	this->sortByYearAndSubjectBtn = new QPushButton("Sort by year and subject");
	this->sortByYearAndSubjectBtn->setFixedSize(160, 40);
	this->mainLayout->addWidget(this->sortByYearAndSubjectBtn);

	this->buildList(this->ctrl.getAll());
	this->mainLayout->addWidget(this->list);
	this->restBtn = new QPushButton("Reset");
	this->restBtn->setFixedSize(50, 50);
	this->mainLayout->addWidget(this->restBtn);
	this->addBtn = new QPushButton("Add");
	this->mainLayout->addWidget(this->addBtn);
	this->deleteBtn = new QPushButton("Delete");
	this->mainLayout->addWidget(this->deleteBtn);
	this->updateBtn = new QPushButton("Update");
	this->mainLayout->addWidget(this->updateBtn);
	this->undo = new QPushButton("Undo");
	this->mainLayout->addWidget(this->undo);



	//filter title layout
	this->filterByTitleLayout = new QFormLayout;
	this->widgetFilterTitle = new QWidget;
	this->filterByTitleSlotBtn = new QPushButton("Filter");
	this->titleFieldFilter = new QLineEdit;
	this->filterByTitleLayout->addRow(new QLabel("Title"), this->titleFieldFilter);
	this->filterByTitleLayout->addWidget(this->filterByTitleSlotBtn);
	this->widgetFilterTitle->setLayout(this->filterByTitleLayout);

	//filter year layout
	this->filterByYearLayout = new QFormLayout;
	this->widgetFilterYear = new QWidget;
	this->filterByYearSlotBtn = new QPushButton("Filter");
	this->yearFieldFilter = new QLineEdit;
	this->filterByYearLayout->addRow(new QLabel("Year"), this->yearFieldFilter);
	this->filterByYearLayout->addWidget(this->filterByYearSlotBtn);
	this->widgetFilterYear->setLayout(this->filterByYearLayout);

	//update layout
	this->widgetUpdate = new QWidget;
	this->updateLayout = new QFormLayout;
	this->idFieldUpdate = new QLineEdit;
	this->idFieldUpdate->setEnabled(false);
	this->updateLayout->addRow(new QLabel("ID"), this->idFieldUpdate);
	this->titleFieldUpdate = new QLineEdit;
	this->updateLayout->addRow(new QLabel("Title"), this->titleFieldUpdate);
	this->authorFieldUpdate = new QLineEdit;
	this->updateLayout->addRow(new QLabel("Author"), this->authorFieldUpdate);
	this->yearFieldUpdate = new QLineEdit;
	this->updateLayout->addRow(new QLabel("Year"), this->yearFieldUpdate);
	this->subjectFieldUpdate = new QLineEdit;
	this->updateLayout->addRow(new QLabel("Subject"), this->subjectFieldUpdate);
	this->widgetUpdate->setWindowTitle("Update Book");
	this->storeUpdate = new QPushButton("&Update");
	this->updateLayout->addWidget(this->storeUpdate);
	this->widgetUpdate->setLayout(this->updateLayout);

	//cart
	this->addCartBtn = new QPushButton("&Add in cart");
	this->mainLayout->addWidget(this->addCartBtn);
	this->emptyCartBtn = new QPushButton("&Empty cart");
	this->mainLayout->addWidget(this->emptyCartBtn);
	this->generateCartBtn = new QPushButton("&Generate cart");
	this->mainLayout->addWidget(this->generateCartBtn);
	this->cartGuiBtn = new QPushButton("&Cart CRUD GUI");
	this->mainLayout->addWidget(this->cartGuiBtn);
	this->cartReadOnlyGuiBtn = new QPushButton("&Cart ReadOnly GUI");
	this->mainLayout->addWidget(this->cartReadOnlyGuiBtn);

	//disable buttons
	this->deleteBtn->setEnabled(false);
	this->updateBtn->setEnabled(false);
	this->addCartBtn->setEnabled(false);

	this->centralWidget()->setLayout(mainLayout);
}
void BibliotecaGUI::connect() {
	QObject::connect(restBtn, &QPushButton::clicked, this, &BibliotecaGUI::clear);
	QObject::connect(addBtn, &QPushButton::clicked, this, &BibliotecaGUI::addSlot);
	QObject::connect(deleteBtn, &QPushButton::clicked, this, &BibliotecaGUI::deleteSlot);
	QObject::connect(updateBtn, &QPushButton::clicked, this, &BibliotecaGUI::updateSlot);
	QObject::connect(store, &QPushButton::clicked, this, &BibliotecaGUI::storeSlot);
	QObject::connect(storeUpdate, &QPushButton::clicked, this, &BibliotecaGUI::storeUpdateSlot);
	QObject::connect(undo, &QPushButton::clicked, this, &BibliotecaGUI::undoSlot);

	QObject::connect(filterByTitleBtn, &QPushButton::clicked, this, &BibliotecaGUI::filterByTitleSlot);
	QObject::connect(filterByTitleSlotBtn, &QPushButton::clicked, this, &BibliotecaGUI::filterByTitle);
	QObject::connect(filterByYearBtn, &QPushButton::clicked, this, &BibliotecaGUI::filterByYearSlot);
	QObject::connect(filterByYearSlotBtn, &QPushButton::clicked, this, &BibliotecaGUI::filterByYear);

	QObject::connect(sortByTitleBtn, &QPushButton::clicked, this, &BibliotecaGUI::sortByTitle);
	QObject::connect(sortByAuthorBtn, &QPushButton::clicked, this, &BibliotecaGUI::sortByAuthor);
	QObject::connect(sortByYearAndSubjectBtn, &QPushButton::clicked, this, &BibliotecaGUI::sortByYearAndSubject);
	QObject::connect(searchField, &QLineEdit::textChanged, this, &BibliotecaGUI::searchByTitle);
	QObject::connect(list, &QListWidget::itemSelectionChanged, this, &BibliotecaGUI::listItemSelected);

	QObject::connect(addCartBtn, &QPushButton::clicked, this, &BibliotecaGUI::addCartSlot);
	QObject::connect(emptyCartBtn, &QPushButton::clicked, this, &BibliotecaGUI::emptyCartSlot);
	QObject::connect(generateCartBtn, &QPushButton::clicked, this, &BibliotecaGUI::generateCartSlot);

	QObject::connect(cartGuiBtn, &QPushButton::clicked, this, &BibliotecaGUI::cartGui);
	QObject::connect(cartReadOnlyGuiBtn, &QPushButton::clicked, this, &BibliotecaGUI::cartReadOnlyGui);
}


void BibliotecaGUI::cartGui() {
	this->widgetCartGui = new CartCRUDGUI(this->ctrl.getCartRepository());
	this->widgetCartGui->show();

}
void BibliotecaGUI::cartReadOnlyGui() {
	this->widgetCartReadOnlyGui = new CartReadOnlyGUI(this->ctrl.getCartRepository());
	//this->widgetCartReadOnlyGui->setFixedHeight(500);
	//this->widgetCartReadOnlyGui->setFixedWidth(500);
	//this->widgetCartReadOnlyGui->setWindowOpacity(0.8);
	this->widgetCartReadOnlyGui->show();

}

void BibliotecaGUI::addCartSlot() {
	QStringList tokens = this->list->selectedItems()[0]->text().split("|");
	int id = tokens[0].toInt();
	string title = tokens[1].toStdString();
	string author = tokens[2].toStdString();
	int year = tokens[3].toInt();
	string subject = tokens[4].toStdString();
	Book book(id, title, author, subject, year);

	this->ctrl.addBookCart(book);
}

void BibliotecaGUI::emptyCartSlot() {
	this->ctrl.emptyCart();
}
void BibliotecaGUI::generateCartSlot() {
	this->ctrl.emptyCart();
	this->ctrl.generateRandomCart(5);
}

void BibliotecaGUI::undoSlot() {
	try {
		this->ctrl.undo();
		this->buildList(this->ctrl.getAll());
	}
	catch (ValidatorException &e) {
		QMessageBox::warning(this, "Warring", QString::fromStdString(e.getMsg()));
	}
}

void BibliotecaGUI::listItemSelected() {
	if (this->list->selectedItems().count() > 0) {
		//enable buttons
		this->deleteBtn->setEnabled(true);
		this->updateBtn->setEnabled(true);
		this->addCartBtn->setEnabled(true);
	}
	else return;
}

void BibliotecaGUI::addSlot() {

	this->widgetAdd->show();
}

void BibliotecaGUI::storeSlot() {
	this->widgetAdd->hide();
	//create book
	std::string title = this->titleFieldAdd->text().toStdString();
	std::string author = this->authorFieldAdd->text().toStdString();
	int year = this->yearFieldAdd->text().toInt();
	std::string subject = this->subjectFieldAdd->text().toStdString();
	try {
		this->ctrl.add(title, author, subject, year);
		this->buildList(this->ctrl.getAll());
	}
	catch (ValidatorException &e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMsg()));
	}
}

void BibliotecaGUI::updateSlot() {
	this->widgetUpdate->show();
	//set fields
	QStringList tokens = this->list->selectedItems()[0]->text().split("|");
	this->idFieldUpdate->setText(tokens[0]);
	this->titleFieldUpdate->setText(tokens[1]);
	this->authorFieldUpdate->setText(tokens[2]);
	this->yearFieldUpdate->setText(tokens[3]);
	this->subjectFieldUpdate->setText(tokens[4]);
}

void BibliotecaGUI::storeUpdateSlot() {
	this->widgetUpdate->hide();
	int id = this->idFieldUpdate->text().toInt();
	std::string title = this->titleFieldUpdate->text().toStdString();
	std::string author = this->authorFieldUpdate->text().toStdString();
	int year = this->yearFieldUpdate->text().toInt();
	std::string subject = this->subjectFieldUpdate->text().toStdString();
	try {
		this->ctrl.update(id, title, author, subject, year);
		this->deleteBtn->setEnabled(false);
		this->updateBtn->setEnabled(false);
		this->buildList(this->ctrl.getAll());
		this->searchField->clear();
	}
	catch (ValidatorException &e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getMsg()));
	}
}

void BibliotecaGUI::deleteSlot() {
	for (int row = 0; row < this->list->selectedItems().count(); row++)
	{
		QStringList tokens = this->list->selectedItems()[row]->text().split("|");
		int id = tokens[row].toInt();
		if (this->ctrl.existId(id))
		{
			this->ctrl.del(id);
			this->deleteBtn->setEnabled(false);
			this->updateBtn->setEnabled(false);
			this->buildList(this->ctrl.getAll());
			this->searchField->clear();
		}
		else {
			QMessageBox::critical(this, "Error", "Nu s-a putut realiza stergerea.");
		}
	}
}
void BibliotecaGUI::clear() {
	this->buildList(this->ctrl.getAll());
}
void BibliotecaGUI::searchByTitle() {
	this->list->clear();
	std::vector<Book> books = this->ctrl.getAll();
	for (auto it = books.begin(); it != books.end(); ++it) {
		Book b = *it;
		if (QString::fromStdString(b.getTitle()).contains(this->searchField->text())) {
			QString book = QString::number(b.getId()) + "|" + QString::fromStdString(b.getTitle()) + "|" + QString::fromStdString(b.getAuthor()) + "|" + QString::number(b.getYear()) + "|" + QString::fromStdString(b.getSubject());
			new QListWidgetItem(book, this->list);
		}
	}

}

void BibliotecaGUI::filterByTitleSlot() {
	this->widgetFilterTitle->show();
}

void BibliotecaGUI::filterByYearSlot() {
	this->widgetFilterYear->show();
}

void BibliotecaGUI::filterByTitle() {
	std::string title = this->titleFieldFilter->text().toStdString();
	this->buildList(this->ctrl.filterByTitle(title));
	this->widgetFilterTitle->hide();


}
void BibliotecaGUI::filterByYear() {
	std::string year = this->yearFieldFilter->text().toStdString();
	this->buildList(this->ctrl.filterByYear(year));
	this->widgetFilterYear->hide();
}
void BibliotecaGUI::sortByTitle() {
	this->buildList(this->ctrl.sortByTitle());
}
void BibliotecaGUI::sortByAuthor() {
	this->buildList(this->ctrl.sortByAuthor());
}
void BibliotecaGUI::sortByYearAndSubject() {
	this->buildList(this->ctrl.sortByYearAndSubject());
}
BibliotecaGUI::~BibliotecaGUI()
{

}
