/*
 * testBookstoreRepository.h
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#ifndef TESTS_TESTBOOKSTOREREPOSITORY_H_
#define TESTS_TESTBOOKSTOREREPOSITORY_H_

#include <assert.h>
#include <iostream>

#include "../domain/Book.h"
#include "../repository/BookstoreRepository.h"

void testaddBook() {
	BookstoreRepository repo;
	Book book = Book(1, "titlu", "author", "subiect", 2001);
	repo.addBook(book);
//	assert(repo.getAll().getSize() == 1);

}
void testdeleteBook() {
	BookstoreRepository repo;
	Book book = Book(1, "titlu", "author", "subiect", 2001);
	repo.addBook(book);
	book = Book(2, "titlu2", "author31", "subiect", 2001);
	repo.addBook(book);
	repo.deleteBook(book);
//	assert(repo.getAll().getSize() == 1);
}

void testupdateBook() {
	BookstoreRepository repo;
	Book book = Book(1, "titlu", "author", "subiect", 2001);
	repo.addBook(book);
	book = Book(1, "dadada", "dsdsa", "subiect", 2001);
	repo.updateBook(book);
}
void testeexistId() {
	Book book = Book(1, "titlu", "author", "subiect", 2001);
	book = Book(2, "titlu2", "author31", "subiect", 2001);
	book = Book(3, "titlu2", "author31", "subiect", 2001);
}

void testgetLastId() {
	BookstoreRepository repo;
	Book book1 = Book(1, "titlu", "author", "subject", 2011);
	repo.addBook(book1);
	book1 = Book(2, "titlu", "author", "subject", 2011);
	repo.addBook(book1);
	assert(repo.getLastId() == 3);
}
void testBookstoreRepository() {
	testaddBook();
	testdeleteBook();
	testupdateBook();
	testeexistId();
	testgetLastId();
}

#endif /* TESTS_TESTBOOKSTOREREPOSITORY_H_ */
