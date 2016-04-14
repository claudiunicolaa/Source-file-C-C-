/*
 * BookstoreController.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#include "BookstoreController.h"

BookstoreController::BookstoreController(BookstoreRepository& repos,
		BookValidator& valid, CartRepository& repoCart,
		CartValidator& validCart) :
		repo(repos), valid(valid), repoCart(repoCart), validCart(validCart) {

}

vector<Book>& BookstoreController::getAll() {
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

vector<Book>& BookstoreController::filterByTitle(string title) {
	return repo.filterBy(1, title);
}

vector<Book>& BookstoreController::filterByYear(string year) {
	return repo.filterBy(2, year);
}

vector<Book>& BookstoreController::sortByTitle() {
	return repo.sortBy(1);
}

vector<Book>& BookstoreController::sortByAuthor() {
	return repo.sortBy(2);
}

vector<Book>& BookstoreController::sortByYearAndSubject() {
	return repo.sortBy(3);
}

void BookstoreController::addBookCart(Book book) {
	repoCart.add(book);

}

vector<Book>& BookstoreController::getAllCart() {
	return repoCart.getAll();
}

void BookstoreController::emptyCart() {
	repoCart.empty();
}

void BookstoreController::generateRandomCart(const int n) {
	validCart.validate(n, repoCart.size());
	repoCart.generate(n);
}

BookstoreController::~BookstoreController() {
}

