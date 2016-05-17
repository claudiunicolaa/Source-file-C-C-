/*
 * BookstoreConsole.h
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#ifndef UI_BOOKSTORECONSOLE_H_
#define UI_BOOKSTORECONSOLE_H_
#include "../controller/BookstoreController.h"

class BookstoreConsole {
private:
	BookstoreController& ctrl;

	/**
	 * Print the menu of application
	 */
	void printMenu();

	/**
	 * Get the command from standard input
	 */
	int getCommand();

	/**
	 * Show all books
	 */
	void showUi(const DynamicArray<Book>&);

	/**
	 * Add a book
	 */
	void addUi();

	/**
	 * Delete a book
	 */
	void deleteUi();

	/**
	 * Update a book
	 */
	void updateUi();

	/**
	 * Search a book
	 */
	void searchBook();

	/**
	 * Filter by title
	 */
	void filterByTitle();

	/**
	 * Filter by year
	 */
	void filterByYear();

	/**
	 * Sort by title
	 */
	void sortByTitle();

	/**
	 * Sort by author
	 */
	void sortByAuthor();

	/**
	 * Sort by year and subject
	 */
	void sortMultiple();
public:
	BookstoreConsole(BookstoreController&);
	BookstoreConsole(BookstoreConsole& other) = delete;

	void runApp();

	virtual ~BookstoreConsole();
};

#endif /* UI_BOOKSTORECONSOLE_H_ */
