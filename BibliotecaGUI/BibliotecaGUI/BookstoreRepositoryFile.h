#pragma once
#include <string>
#include <vector>
#include "Book.h"
#include "Validator.h"
#include <fstream>
#include "BookstoreRepository.h"

class BookstoreRepositoryFile : public BookstoreRepository {
private:
	std::string fileName;
	virtual void loadFromFile();
	virtual void writeToFile();
public:
	BookstoreRepositoryFile(const std::string fileName) :
		BookstoreRepository(), fileName(fileName) {
		loadFromFile();
	}

	void addBook(Book& book) override {
		BookstoreRepository::addBook(book);
		writeToFile();
	}

	void deleteBook(Book& book) override {
		BookstoreRepository::deleteBook(book);
		writeToFile();
	}

	virtual ~BookstoreRepositoryFile() {
	}
};