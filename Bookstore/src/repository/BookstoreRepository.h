/*
 * BookstoreRepository.h
 *
 *  Created on: Mar 28, 2016
 *      Author: claudiu
 */

#ifndef REPOSITORY_BOOKSTOREREPOSITORY_H_
#define REPOSITORY_BOOKSTOREREPOSITORY_H_

#include "../domain/Book.h"
#include "../util/DynamicArray.h"

class BookstoreRepository {
private:
	DynamicArray<Book> books;
public:
	BookstoreRepository() {
	}

	/**
	 * Add a book in memory
	 */
	void addBook(Book&);

	/**
	 * Delete a book from memory
	 */
	void deleteBook(Book&);

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

	DynamicArray<Book>& getAll() {
		return books;
	}

	DynamicArray<Book>& sortBy(const int);

	DynamicArray<Book> filterBy(const int, string);

	BookstoreRepository(const BookstoreRepository& other) = delete;
};

#endif /* REPOSITORY_BOOKSTOREREPOSITORY_H_ */
