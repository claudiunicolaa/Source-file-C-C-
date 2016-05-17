/*
 * BookstoreController.h
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#ifndef CONTROLLER_BOOKSTORECONTROLLER_H_
#define CONTROLLER_BOOKSTORECONTROLLER_H_
#include "../repository/BookstoreRepository.h"
#include "../domain/Validator.h"

class BookstoreController {
private:
	BookstoreRepository& repo;
	BookValidator& valid;
public:
	BookstoreController(BookstoreRepository&, BookValidator&);
	DynamicArray<Book>& getAll();
	void add(string, string, string, int);
	void del(int);
	void update(int, string, string, string, int);
	bool existId(int);
	Book existTitle(string);
	Book getBookById(int);
	DynamicArray<Book> filterByTitle(string);
	DynamicArray<Book> filterByYear(string);
	DynamicArray<Book>& sortByTitle();
	DynamicArray<Book>& sortByAuthor();
	DynamicArray<Book>& sortByYearAndSubject();

	BookstoreController(BookstoreController& other) = delete;
	virtual ~BookstoreController();
};

#endif /* CONTROLLER_BOOKSTORECONTROLLER_H_ */
