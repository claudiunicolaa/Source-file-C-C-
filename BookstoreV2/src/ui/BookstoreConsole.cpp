/*
 * BookstoreConsole.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#include "BookstoreConsole.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../domain/Book.h"
#include "../domain/Validator.h"
#include "../util/DynamicArray.h"

BookstoreConsole::BookstoreConsole(BookstoreController& ctrl) :
		ctrl(ctrl) {

}

/**
 * Print the menu of application
 */
void BookstoreConsole::printMenu() {
	cout << "BIBLIOTECA" << endl;
	cout << "1. Afiseaza carti." << endl;
	cout << "2. Adauga carte." << endl;
	cout << "3. Sterge carte." << endl;
	cout << "4. Modifica carte." << endl;
	cout << "5. Cauta carte dupa titlu." << endl;
	cout << "6. Filtrare dupa titlu." << endl;
	cout << "7. Filtrare dupa anul aparitiei." << endl;
	cout << "8. Sortare dupa titlu." << endl;
	cout << "9. Sortare dupa autor." << endl;
	cout << "10.Sortare dupa anul aparitiei+gen." << endl;
	cout << "11.Afiseaza cos." << endl;
	cout << "12.Adauga in cos." << endl;
	cout << "13.Goleste cos." << endl;
	cout << "14.Genreaza cos." << endl;
	cout << "0. Iesire." << endl;
}

/**
 * Get the command from standard input
 */
int BookstoreConsole::getCommand() {
	int cmd;
	cout << "Alegeti o optiune:";
	cin >> cmd;
	return cmd;
}

/**
 * Print a Book
 */

/**
 * Show all books
 */
void BookstoreConsole::showUi(const vector<Book>& books) {
//	if (books.getSize() == 0) {
//		cout << "Nu exista carti." << endl;
//	}
//	for (int i = 0; i < books.getSize(); i++) {
//		Book b = books.get(i);
//		cout << b << endl;
//	}
	for (auto it = books.begin(); it != books.end(); ++it)
		cout << *it << endl;
}

bool checkInput() {
	return true;
}
/**
 * Add a book
 */
void BookstoreConsole::addUi() {
	string title;
	string author;
	string subject;
	int year;
	cout << "Adaugare carte" << endl;
	cout << "Titlu:" << endl;
	cin >> title;
	cout << "Autor:" << endl;
	cin >> author;
	cout << "Genul:" << endl;
	cin >> subject;
	cout << "Anul aparitiei:" << endl;
	cin >> year;
	try {
		ctrl.add(title, author, subject, year);
	} catch (ValidatorException& err) {
		cout << err.getMsg() << endl;
	}

}

/**
 * Delete a book
 */
void BookstoreConsole::deleteUi() {
	int id;
	cout << "Sterge carte" << endl;
	cout << "Id-ul carti:" << endl;
	cin >> id;
	if (ctrl.existId(id)) {
		ctrl.del(id);
	} else {
		cout << "Id-ul introdus nu exista" << endl;
	}

}

/**
 * Update a book
 */
void BookstoreConsole::updateUi() {
	int id;
	string title;
	string author;
	string subject;
	int year;
	cout << "Modifica carte" << endl;
	cout << "Id-ul carti:" << endl;
	cin >> id;
	if (ctrl.existId(id)) {
		Book book = ctrl.getBookById(id);
		cout << book << endl;
		cout << "Titlu:" << endl;
		cin >> title;
		cout << "Autor:" << endl;
		cin >> author;
		cout << "Genul:" << endl;
		cin >> subject;
		cout << "Anul aparitiei:" << endl;
		cin >> year;
		try {
			ctrl.update(id, title, author, subject, year);
			cout << "Date modificate cu succes." << endl;
			cout << ctrl.getBookById(id) << endl;
		} catch (ValidatorException& err) {
			cout << err.getMsg() << endl;
		}
	} else {
		cout << "Id-ul introdus nu exista" << endl;
	}
}

/**
 * Filter by title
 */
void BookstoreConsole::filterByTitle() {
	string title;
	cout << "Filtrare dupa titlu" << endl;
	cout << "Titlul:" << endl;
	cin >> title;
	vector<Book> books = ctrl.filterByTitle(title);
//	showUi(books);
}

/**
 * Filter by year
 */
void BookstoreConsole::filterByYear() {
	string year;
	cout << "Filtrare dupa an" << endl;
	cout << "Anul aparitiei:" << endl;
	cin >> year;
	vector<Book> books = ctrl.filterByYear(year);
//	showUi(books);
}

/**
 * Sort by title
 */
void BookstoreConsole::sortByTitle() {
	cout << "Sortare dupa titlu" << endl;
	vector<Book> books = ctrl.sortByTitle();
//	showUi(books);
}

/**
 * Sort by author
 */
void BookstoreConsole::sortByAuthor() {
	cout << "Sortare dupa autor" << endl;
	vector<Book> books = ctrl.sortByAuthor();
//	showUi(books);
}

/**
 * Sort by year and subject
 */
void BookstoreConsole::sortMultiple() {
	cout << "Sortare dupa an + gen" << endl;
	vector<Book> books = ctrl.sortByYearAndSubject();
//	showUi(books);
}

void BookstoreConsole::searchBook() {
	string title;
	cout << "Cautare carte" << endl;
	cout << "Titlul carti" << endl;
	cin >> title;
	Book book = ctrl.existTitle(title);
	//if not exist the book, existTitle return a book with
	// id -1
	if (book.getId() > 0)
		cout << book << endl;
	else
		cout << "Carte nu exista" << endl;
}

void BookstoreConsole::addBookCart() {
	int id;
	cout << "Adauga carte in cos" << endl;
	cout << "Id-ul cartii: " << endl;
	cin >> id;
	if (ctrl.existId(id)) {
		Book book = ctrl.getBookById(id);
		ctrl.addBookCart(book);
	} else {
		cout << "Id-ul nu exista" << endl;
	}
}

void BookstoreConsole::emptyCart() {
	ctrl.emptyCart();
}

void BookstoreConsole::generateCart() {
	int n;
	cout << "Genereaza cos" << endl;
	cout << "Numarul de carti: " << endl;
	cin >> n;
	try {
		ctrl.generateRandomCart(n);
	} catch (ValidatorException& errMsg) {
		cout << errMsg.getMsg() << endl;
	}
}

void BookstoreConsole::runApp() {
	while (true) {
		printMenu();
		int cmd = getCommand();
		if (cmd == 0) {
			cout << "La revedere!";
			break;
		}
		switch (cmd) {
		case 1:
			showUi(ctrl.getAll());
			break;
		case 2:
			addUi();
			break;
		case 3:
			deleteUi();
			break;
		case 4:
			updateUi();
			break;
		case 5:
			searchBook();
			break;
		case 6:
			filterByTitle();
			break;
		case 7:
			filterByYear();
			break;
		case 8:
			sortByTitle();
			break;
		case 9:
			sortByAuthor();
			break;
		case 10:
			sortMultiple();
			break;
		case 11:
			showUi(ctrl.getAllCart());
			break;
		case 12:
			addBookCart();
			break;
		case 13:
			emptyCart();
			break;
		case 14:
			generateCart();
			break;
		default:
			cout << "Optiune nu este implementata!" << endl;
			break;
		}
	}
}
BookstoreConsole::~BookstoreConsole() {
	// TODO Auto-generated destructor stub
}

