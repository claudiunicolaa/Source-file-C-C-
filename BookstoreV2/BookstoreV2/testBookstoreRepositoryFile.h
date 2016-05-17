#pragma once
#include "BookstoreRepositoryFile.h"
#include <assert.h>
void testLoadFromFile() {
	try {
		BookstoreRepositoryFile repo("test.txt");
		vector<Book> boo = repo.getAll();
		int a = boo.size();
		assert(a == 5);
		assert(boo[0].getId() == 1);
		assert(boo[1].getTitle() == "Enigma Otiliei");
		assert(boo[2].getAuthor() == "I. Slavici");
		assert(boo[3].getSubject() == "Nuvela");
		assert(boo[4].getYear() == 1800);
	}
	catch (BookstoreRepositoryFileExceptions& ex) {

	}
}

void testWriteInFile() {
	try {
		BookstoreRepositoryFile repo("test.txt");
		Book b(1, "Cartea Junglei", "Whatever", "Copii", 19561);
				//repo.addBook(b);
	}
	catch (BookstoreRepositoryFileExceptions& ex) {
	}
}
void testBookstoreRepositoryFile() {
	testLoadFromFile();
	testWriteInFile();
}
