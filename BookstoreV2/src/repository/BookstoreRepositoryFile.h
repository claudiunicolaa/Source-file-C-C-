/*
 * BookstoreRepositoryFile.h
 *
 *  Created on: Apr 12, 2016
 *      Author: claudiu
 */

#ifndef REPOSITORY_BOOKSTOREREPOSITORYFILE_H_
#define REPOSITORY_BOOKSTOREREPOSITORYFILE_H_

#include <string>

#include "BookstoreRepository.h"

class BookstoreRepositoryFile: public BookstoreRepository {
private:
	std::string fileName;
	void loadFromFile();
	void writeToFile();
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

#endif /* REPOSITORY_BOOKSTOREREPOSITORYFILE_H_ */
