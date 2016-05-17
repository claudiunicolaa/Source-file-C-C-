#include "stdafx.h"
#include "BookstoreRepository.h"

/**
* Add a book in memory
*/
void BookstoreRepository::addBook(Book& book) {
	books.push_back(book);
}

/**
* Delete a book from memory
*/
void BookstoreRepository::deleteBook(Book& book) {
	for (auto it = books.begin(); it != books.end(); ++it) {
		auto current = *it;
		if (current.getId() == book.getId()) {
			books.erase(it);
			return;
		}
	}
}

/**
* Update a book in memory
*/
void BookstoreRepository::updateBook(Book& book) {
	for (auto it = books.begin(); it != books.end(); ++it) {
		auto current = *it;
		if (current.getId() == book.getId())
			books.at(it - books.begin()) = book;
	}
}

/**
* Check if exist id
*/
bool BookstoreRepository::existId(const int id) {
	for (auto it = books.begin(); it != books.end(); ++it) {
		auto current = *it;
		if (current.getId() == id)
			return true;
	}
	return false;
}

/**
* Check if exist the title
*/
Book BookstoreRepository::existTitle(string title) {
	Book b;
	for (auto it = books.begin(); it != books.end(); ++it) {
		auto b = *it;
		if (title == b.getTitle())
			return b;
	}
	b.setId(-1);
	return b;
}

/**
* Get the last id from data
*/
int BookstoreRepository::getLastId() {
	int id = 0;
	for (auto it = books.begin(); it != books.end(); ++it) {
		auto current = *it;
		if (current.getId() > id)
			id = current.getId();
	}
	return id + 1;
}

/**
* Get by id
*/
Book BookstoreRepository::getById(const int id) {
	Book b;
	for (auto it = books.begin(); it != books.end(); ++it) {
		auto b = *it;
		if (id == b.getId())
			return b;
	}
	return b;
}

vector<Book>& BookstoreRepository::sortBy(const int theCase) {
	vector<Book>& b = books;
	switch (theCase) {
		//title
	case 1:
		sort(b.begin(), b.end(),
			[](const Book& b1, const Book& b2) {return b1.getTitle() < b2.getTitle(); });
		break;
		//author
	case 2:
		sort(b.begin(), b.end(),
			[](const Book& b1, const Book& b2) {return b1.getAuthor() < b2.getAuthor(); });
		break;
		//year+subject
	default:
		sort(b.begin(), b.end(),
			[](const Book& b1, const Book& b2) {return (b1.getYear() < b2.getYear()) ||
			((b1.getYear() == b2.getYear()) && (b1.getSubject() < b2.getSubject())); });
		break;
	}
	return b;
}

vector<Book> BookstoreRepository::filterBy(const int theCase, string field) {
	vector<Book> b;
	switch (theCase) {
		//title
	case 1: {
		//		std::copy_if(books.begin(), books.end(), b.begin(),
		//				[&](const Book& book) {return book.getTitle()==field;});
		for (auto it = books.begin(); it < books.end(); ++it) {
			auto current = *it;
			if (current.getTitle() == field)
				b.push_back(current);
		}
		break;
	}
			//year
	case 2: {
		for (auto it = books.begin(); it < books.end(); ++it) {
			auto current = *it;
			if (current.getYear() == std::stoi(field))
				b.push_back(current);
		}
		break;
	}
	}
	return b;
}