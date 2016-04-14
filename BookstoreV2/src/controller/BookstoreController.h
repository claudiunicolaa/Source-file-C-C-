/*
 * BookstoreController.h
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#ifndef CONTROLLER_BOOKSTORECONTROLLER_H_
#define CONTROLLER_BOOKSTORECONTROLLER_H_

#include <string>
#include <vector>

#include "../domain/Book.h"
#include "../util/DynamicArray.h"
#include "../repository/BookstoreRepository.h"
#include "../domain/Validator.h"
#include "../repository/CartRepository.h"


class BookstoreController {
private:
	BookstoreRepository& repo;
	BookValidator& valid;
	CartRepository& repoCart;
	CartValidator& validCart;
public:
	BookstoreController(BookstoreRepository&, BookValidator&, CartRepository&, CartValidator& );
	vector<Book>& getAll();
	void add(string, string, string, int);
	void del(int);
	void update(int, string, string, string, int);
	bool existId(int);
	Book existTitle(string);
	Book getBookById(int);
	vector<Book>& filterByTitle(string);
	vector<Book>& filterByYear(string);
	vector<Book>& sortByTitle();
	vector<Book>& sortByAuthor();
	vector<Book>& sortByYearAndSubject();
	void addBookCart(Book);
	vector<Book>& getAllCart();
	void emptyCart();
	void generateRandomCart(const int);

	BookstoreController(BookstoreController& other) = delete;
	virtual ~BookstoreController();
};

#endif /* CONTROLLER_BOOKSTORECONTROLLER_H_ */
