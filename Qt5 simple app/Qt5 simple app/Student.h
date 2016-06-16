#pragma once
#include <string>

class Student
{
private:
	std::string name;
	std::string university;
	double finalGrade;
public:

	friend std::ostream& operator<<(std::ostream& os, const Student& student) {
		os << student.name << " " << student.university << " " << student.finalGrade;

		return os;
	}

	/*
		Default constructor
	*/
	Student() {
		this->name = "";
		this->university = "";
		this->finalGrade = 0;
	}

	/*
		Constructor with 3 params
	*/
	Student(const std::string name, const std::string university, const double finalGrade) {
		this->name = name;
		this->university = university;
		this->finalGrade = finalGrade;
	}

	/*
		Copy constructor
	*/
	Student(const Student& other) {
		this->name = other.name;
		this->university = other.university;
		this->finalGrade = other.finalGrade;
	}

	/*
		Get the name
	*/
	std::string getName() {
		return this->name;
	}

	/*
		Get the university
	*/
	std::string getUniversity() {
		return this->university;
	}

	/*
		Get the final grade
	*/
	double getFinalGrade() {
		return this->finalGrade;
	}

	/*
		Set the name
	*/
	void setName(const std::string name) {
		this->name = name;
	}

	/*
		Set the university
	*/
	void setUniversity(const std::string university) {
		this->university = university;
	}

	/*
		Set the final grade
	*/
	void setFinalGrade(const double finalGrade) {
		this->finalGrade = finalGrade;
	}

	/*
		Override the = operator.
		When do student1 = student2 the content of student1 will be
		coppied in student2
	*/
	Student& operator=(const Student& other) {
		if (this != &other) {
			this->name = other.name;
			this->university = other.university;
			this->finalGrade = other.finalGrade;
		}
		return *this;
	}

	/*
		Override the == operator
	*/
	bool operator==(Student& other) {

		if (this->name != other.getName()) {
			return false;
		}

		if (this->university != other.getUniversity()) {
			return false;
		}

		if (this->finalGrade != other.getFinalGrade()) {
			return false;
		}

		return true;
	}

	~Student() {}
};

