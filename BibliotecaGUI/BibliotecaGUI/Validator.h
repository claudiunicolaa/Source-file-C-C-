#pragma once
#include <exception>
#include <string>
#include "Book.h"

using namespace std;

/**
* Generic exception used in the application
* We will derive specialized exceptions from this class
*/
class MyExceptions : public exception {
private:
	string msg;
public:
	MyExceptions(string& msg) {
		this->msg = msg;
	}
	const string& getMsg() {
		return msg;
	}
};

class ValidatorException : public MyExceptions {
public:
	ValidatorException(string msg) :
		MyExceptions(msg) {
	}
};

class BookValidator {
public:
	void validate(Book book) throw (ValidatorException);

};

class CartValidator {
public:
	void validate(const int, const int) throw (ValidatorException);
};

class BookstoreRepositoryFileExceptions : public ValidatorException {
public:
	BookstoreRepositoryFileExceptions(string msg) :
		ValidatorException(msg) {
	}
};