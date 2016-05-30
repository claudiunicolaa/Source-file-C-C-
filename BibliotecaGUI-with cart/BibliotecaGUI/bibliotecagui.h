#ifndef BIBLIOTECAGUI_H
#define BIBLIOTECAGUI_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QCompleter>
#include "BookstoreController.h"
#include "CartCRUDGUI.h"
#include "CartReadOnlyGui.h"
#include <string.h>
#include <QString>
#include "ui_bibliotecagui.h"

class BibliotecaGUI : public QMainWindow
{
	Q_OBJECT

public:
	BibliotecaGUI(BookstoreController& ctrl, QWidget *parent = 0);
	void buildWindow();
	void buildList(std::vector<Book> books);
	void connect();
	void filterByTitleSlot();
	void filterByYearSlot();
	void addSlot();
	void storeSlot();
	void updateSlot();
	void storeUpdateSlot();
	void deleteSlot();
	void clear();
	void searchByTitle();
	void filterByTitle();
	void filterByYear();
	void sortByTitle();
	void sortByAuthor();
	void sortByYearAndSubject();
	void listItemSelected();
	void undoSlot();
	void addCartSlot();
	void emptyCartSlot();
	void generateCartSlot();
	void cartGui();
	void cartReadOnlyGui();
	~BibliotecaGUI();

private:
	Ui::BibliotecaGUIClass ui;
	BookstoreController& ctrl;
	QVBoxLayout *mainLayout;
	QFormLayout *addLayout, *updateLayout, *filterByTitleLayout, *filterByYearLayout;
	QWidget *widgetAdd, *widgetUpdate, *widgetFilterTitle, *widgetFilterYear;
	QListWidget *list;
	QStringList titlesList;
	QLineEdit *titleFieldAdd, *authorFieldAdd, *yearFieldAdd, *subjectFieldAdd, *searchField, *idFieldUpdate, *titleFieldUpdate, *authorFieldUpdate, *yearFieldUpdate, *subjectFieldUpdate, *titleFieldFilter, *yearFieldFilter;
	QPushButton *restBtn, *addBtn, *deleteBtn, *store, *updateBtn, *storeUpdate, *searchBtn, *filterByTitleBtn, *filterByYearBtn, *sortByTitleBtn, *sortByAuthorBtn, *sortByYearAndSubjectBtn, *filterByTitleSlotBtn, *filterByYearSlotBtn, *undo, *addCartBtn, *emptyCartBtn, *generateCartBtn,
		*cartGuiBtn, *cartReadOnlyGuiBtn;
	CartCRUDGUI *widgetCartGui;
	CartReadOnlyGUI *widgetCartReadOnlyGui;
};

#endif // BIBLIOTECAGUI_H
