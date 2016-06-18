#pragma once
#include <exception>
#include <string>
#include "Nota.h"

/*
	Exceptie generic folosita in aplicatie
	Toate exceptile corepunzatoare app o vor mosteni
*/
class MyExceptions :public std::exception {
private:
	std::string msg;
public:
	MyExceptions(const std::string& msg) {
		this->msg = msg;
	}

	const std::string& getMsg() {
		return this->msg;
	}
};


class RepoExceptions : public MyExceptions {
public:
	RepoExceptions(std::string msg) :
		MyExceptions(msg) {
	}
};

class Validator : public MyExceptions {
public:
	Validator(std::string msg) :
		MyExceptions(msg) {
	}

};

class NotaValidator {
public:
	void validate(Nota nota) throw (Validator) {
		if (nota.getStudent() == "") {
			throw Validator("Nota trebuie sa aiba un student");
		}
		if (nota.getProfesor() == "") {
			throw Validator("Nota trebuie sa aiba un profesor");
		}
		if (nota.getValoare() < 0 || nota.getValoare() > 10) {
			throw Validator("Valoare notei trebuie sa fie intre 0-10");
		}
	}
};