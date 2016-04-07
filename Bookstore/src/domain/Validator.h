/*
 * Validator.h
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#ifndef DOMAIN_VALIDATOR_H_
#define DOMAIN_VALIDATOR_H_

#include <string>
#include "../domain/Book.h"

using namespace std;

/**
 * Generic exception used in the application
 * We will derive specialized exceptions from this class
 */
class MyExceptions {
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
	/**
	 * validate a medicine
	 * a medicine is valid if the name,the producer and the active substance
	 * are not empty
	 * throw ValidateException if the product is invalid
	 */
	void validate(Book book) throw (ValidatorException);

};
#endif /* DOMAIN_VALIDATOR_H_ */
