/*
 * BookstoreRepository.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: claudiu
 */

#include "BookstoreRepository.h"

#include <string>
#include <algorithm>

/**
 * Add a book in memory
 */
void BookstoreRepository::addBook(Book& book) {
	books + book;
}

/**
 * Delete a book from memory
 */
void BookstoreRepository::deleteBook(Book& book) {
	books - book;
}

/**
 * Update a book in memory
 */
void BookstoreRepository::updateBook(Book& book) {
	auto iterator = books.being();
	auto endIterator = books.end();
	while (iterator != endIterator) {
		auto current = *iterator;
		if (current.getId() == book.getId()) {
			books - current;
			books + book;
			break;
		}
		++iterator;
	}
}

/**
 * Check if exist id
 */
bool BookstoreRepository::existId(const int id) {
	auto iterator = books.being();
	auto endIterator = books.end();
	while (iterator != endIterator) {
		auto current = *iterator;
		if (current.getId() == id)
			return true;
		++iterator;

	}
	return false;
}

/**
 * Check if exist the title
 */
Book BookstoreRepository::existTitle(string title) {
	Book b;
	auto iterator = books.being();
	auto endIterator = books.end();
	while (iterator != endIterator) {
		b = *iterator;
		if (title == b.getTitle())
			return b;
		++iterator;
	}
	b.setId(-1);
	return b;
}

/**
 * Get the last id from data
 */
int BookstoreRepository::getLastId() {
	auto iterator = books.being();
	auto endIterator = books.end();
	int id = 0;
	while (iterator != endIterator) {
		auto current = *iterator;
		if (current.getId() > id)
			id = current.getId();
		++iterator;
	}
	return id + 1;
}

/**
 * Get by id
 */
Book BookstoreRepository::getById(const int id) {
	Book b;
	auto iterator = books.being();
	auto endIterator = books.end();
	while (iterator != endIterator) {
		b = *iterator;
		if (id == b.getId())
			break;
		++iterator;
	}
	return b;
}

DynamicArray<Book>& BookstoreRepository::sortBy(const int theCase) {
	DynamicArray<Book>& b = books;
	Book aux;
	Book aux1;
	switch (theCase) {
	//title
	case 1:
		for (int i = 0; i < b.getSize(); ++i)
			for (int j = i + 1; j < b.getSize(); ++j)
				if (b.get(i).getTitle() > b.get(j).getTitle()) {
					aux = b.get(i);
					aux1 = b.get(j);
					b.updateElem(i, aux1);
					b.updateElem(j, aux);
				}
//		b.get(0) = b.get(1);
		break;
		//author
	case 2:
		for (int i = 0; i < b.getSize(); ++i)
			for (int j = i + 1; j < b.getSize(); ++j)
				if (b.get(i).getAuthor() > b.get(j).getAuthor()) {
					aux = b.get(i);
					aux1 = b.get(j);
					b.updateElem(i, aux1);
					b.updateElem(j, aux);
				}
		break;
		//year+subject
	default:
		for (int i = 0; i < b.getSize(); ++i)
			for (int j = i + 1; j < b.getSize(); ++j)
				if (b.get(i).getYear() > b.get(j).getYear()) {
					aux = b.get(i);
					aux1 = b.get(j);
					b.updateElem(i, aux1);
					b.updateElem(j, aux);
				} else if (b.get(i).getYear() == b.get(j).getYear()
						&& b.get(i).getSubject() > b.get(j).getSubject()) {
					aux = b.get(i);
					aux1 = b.get(j);
					b.updateElem(i, aux1);
					b.updateElem(j, aux);
				}
		break;
	}
	return b;
}

DynamicArray<Book> BookstoreRepository::filterBy(const int theCase,
		string cmp) {
	DynamicArray<Book> filtered;
	auto iterator = books.being();
	auto endIterator = books.end();
	Book b;
	if (theCase == 1) {
		//filter by title
		while (iterator != endIterator) {
			b = *iterator;
			if (b.getTitle() == cmp)
				filtered + b;
			++iterator;
		}
	} else if (theCase == 2) {
		//filter year
		int intCmp = std::stoi(cmp);
		while (iterator != endIterator) {
			b = *iterator;
			if (b.getYear() == intCmp)
				filtered + b;
			++iterator;
		}
	}

	return filtered;
}

bool compareTitle(Book b1, Book b2) {
	return (b1.getTitle() < b2.getTitle());
}

bool compareAuthor(Book b1, Book b2) {
	return (b1.getAuthor() < b2.getAuthor());
}
