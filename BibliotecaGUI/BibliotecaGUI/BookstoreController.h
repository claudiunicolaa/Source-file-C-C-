#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Book.h"
#include "BookstoreRepository.h"
#include "Validator.h"
#include "CartRepository.h"
#include "Undo.h"


class BookstoreController {
private:
	BookstoreRepository& repo;
	BookValidator& valid;
	CartRepository& repoCart;
	CartValidator& validCart;
	// unique_ptr deallocate the memory for UndoActions
	std::vector<unique_ptr<UndoAction>> undoActions;
public:
	BookstoreController(BookstoreRepository&, BookValidator&, CartRepository&, CartValidator&);
	vector<Book>& getAll();
	void add(string, string, string, int);
	void del(int);
	void update(int, string, string, string, int);
	bool existId(int);
	Book existTitle(string);
	Book getBookById(int);
	vector<Book> filterByTitle(string);
	vector<Book> filterByYear(string);
	vector<Book>& sortByTitle();
	vector<Book>& sortByAuthor();
	vector<Book>& sortByYearAndSubject();
	void addBookCart(Book);
	vector<Book>& getAllCart();
	void emptyCart();
	void generateRandomCart(const int);
	void exportTo(const int);
	void undo();

	BookstoreController(BookstoreController& other) = delete;
	virtual ~BookstoreController();
};