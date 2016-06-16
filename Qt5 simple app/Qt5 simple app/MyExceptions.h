#pragma once
#include <exception>
#include <string>
#include "Student.h"

/*
	Generic exception used in the application
	We will derive specialized exceptions from this class
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

class StudentValidator {
public:
	void validate(Student student) throw (Validator) {
		if (student.getName() == "") {
			throw Validator("Student must have name");
		}
		if (student.getUniversity() == "") {
			throw Validator("Student must have univesity");
		}
		if (student.getFinalGrade() < 0 || student.getFinalGrade() > 10) {
			throw Validator("Student final grade must be between 0-10");
		}
	}
};