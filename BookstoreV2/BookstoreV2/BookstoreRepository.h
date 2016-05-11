#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "Book.h"

class BookstoreRepository {
private:
	std::vector<Book> books;

public:
	BookstoreRepository() {
	}

	/**
	* Add a book in memory
	*/
	virtual void addBook(Book&);

	/**
	* Delete a book from memory
	*/
	virtual void deleteBook(Book&);

	/**
	* Update a book in memory
	*/
	void updateBook(Book&);

	/**
	* Check if exist id
	*/
	bool existId(const int);

	/**
	* Check if exist the title
	* Return book if exist, or a book with -1 id if not
	*/
	Book existTitle(string);

	/**
	* Get the last id from data
	*/
	int getLastId();

	/**
	* Get by id
	*/
	Book getById(const int);

	vector<Book>& getAll() {
		return books;
	}

	vector<Book>& sortBy(const int);

	vector<Book> filterBy(const int, string);

	BookstoreRepository(const BookstoreRepository& other) = delete;
};
