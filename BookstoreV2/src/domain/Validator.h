/*
 * Validator.h
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#ifndef DOMAIN_VALIDATOR_H_
#define DOMAIN_VALIDATOR_H_

#include <exception>
#include <string>
#include"../domain/Book.h"

using namespace std;

/**
 * Generic exception used in the application
 * We will derive specialized exceptions from this class
 */
class MyExceptions: public exception {
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

class ValidatorException: public MyExceptions {
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
#endif /* DOMAIN_VALIDATOR_H_ */
