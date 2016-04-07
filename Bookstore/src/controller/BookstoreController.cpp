/*
 * BookstoreController.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#include "BookstoreController.h"

BookstoreController::BookstoreController(BookstoreRepository& repos,
		BookValidator& valid) :
		repo(repos), valid(valid) {

}

DynamicArray<Book>& BookstoreController::getAll() {
	return repo.getAll();
}

void BookstoreController::add(string title, string author, string subject,
		int year) {
	int id = repo.getLastId();
	Book book(id, title, author, subject, year);
	valid.validate(book);
	repo.addBook(book);
}

void BookstoreController::del(int id) {
	Book book = repo.getById(id);
	repo.deleteBook(book);

}

void BookstoreController::update(int id, string title, string author,
		string subject, int year) {
	Book book(id, title, author, subject, year);
	valid.validate(book);
	repo.updateBook(book);
}

bool BookstoreController::existId(int id) {
	return repo.existId(id);
}

Book BookstoreController::existTitle(string title) {
	return repo.existTitle(title);
}

Book BookstoreController::getBookById(int id) {
	return repo.getById(id);
}

DynamicArray<Book> BookstoreController::filterByTitle(string title) {
	return repo.filterBy(1, title);
}

DynamicArray<Book> BookstoreController::filterByYear(string year) {
	return repo.filterBy(2, year);
}

DynamicArray<Book>& BookstoreController::sortByTitle(){
	return repo.sortBy(1);
}

DynamicArray<Book>& BookstoreController::sortByAuthor(){
	return repo.sortBy(2);
}

DynamicArray<Book>& BookstoreController::sortByYearAndSubject(){
	return repo.sortBy(3);
}

BookstoreController::~BookstoreController() {
}

