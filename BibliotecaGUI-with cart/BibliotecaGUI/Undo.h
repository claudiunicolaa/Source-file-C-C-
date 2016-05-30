#pragma once

#include "Book.h"
#include "BookstoreRepository.h"

//Clasa abstracta
class UndoAction {
public:
	//Metoda abstracta
	virtual void doUndo() = 0;
	virtual ~UndoAction() {
	}
};

class UndoAdd : public UndoAction {
	Book addedBook;
	BookstoreRepository& repo;
public:
	UndoAdd(BookstoreRepository& repo, const Book& b) :
		repo(repo), addedBook(b) {
	}

	void doUndo() override {
		repo.deleteBook(addedBook);
	}
};

class UndoDelete : public UndoAction {
	Book deletedBook;
	BookstoreRepository& repo;
public:
	UndoDelete(BookstoreRepository& repo, const Book& b) :
		repo(repo), deletedBook(b) {
	}

	void doUndo() override {
		repo.addBook(deletedBook);
	}
};

class UndoUpdate : public UndoAction {
	Book oldBook;
	Book updatedBook;
	BookstoreRepository& repo;
public:
	UndoUpdate(BookstoreRepository& repo, const Book& oldBook, const Book& b) : repo(repo), oldBook(oldBook), updatedBook(b) {
	}

	void doUndo() override {
		repo.deleteBook(updatedBook);
		repo.addBook(oldBook);
	}
};

