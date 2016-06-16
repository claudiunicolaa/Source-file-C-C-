#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "MyExceptions.h"
#include "Student.h"
#include <assert.h>


class Repository {
private:
	/*
		The list of students
	*/
	std::vector<Student> students;

	/*
		File that contain students
	*/
	std::string fileName;

	void split(const std::string& s, const char c, std::vector<std::string>& v) {
		std::string::size_type i = 0;
		std::string::size_type j = s.find(c);

		while (j != std::string::npos) {
			v.push_back(s.substr(i, j - i));
			i = ++j;
			j = s.find(c, j);
			if (j == std::string::npos)
				v.push_back(s.substr(i, s.length()));
		}
	}

public:
	Repository(std::string fileName) {
		this->fileName = fileName;
		readFromFile();
	}

	/*
		Add an student
	*/
	void addStudent(const Student& student) {
		this->students.push_back(student);
	}

	/*
		Remove an student
	*/
	void removeStudent(Student& student) {
		for (auto it = this->students.begin(); it != this->students.end(); ++it) {
			auto current = *it;
			if (current == student) {
				this->students.erase(it);
				return;
			}
		}
	}

	/*
		Update an student
	*/
	void updateStudent(Student& oldStudent, const Student& newStudent) {
		for (int i = 0; i < this->students.size(); ++i) {
			if (this->students[i] == oldStudent) {
				this->students[i] = newStudent;
				return;
			}
		}
	}

	/*
		Write in file
	*/
	void writeInFile() {
		std::ofstream out(this->fileName);
		if (!out.is_open()) {
			throw RepoExceptions("Error: Can not open the file(" + this->fileName + ")");
		}

		for (auto& student : this->students) {
			out << student.getName() << '|' << student.getUniversity()
				<< '|' << student.getFinalGrade() << std::endl;
		}

		out.close();
	}

	/*
		Read from file
	*/
	void readFromFile() {
		std::string line;
		std::ifstream in(this->fileName);

		if (!in.is_open()) {
			throw RepoExceptions("Error: Can not open the file(" + this->fileName + ")");
		}

		while (std::getline(in, line)) {
			std::vector<std::string> tokens;
			this->split(line, '|', tokens);
			//tokens[0]->name, tokens[1]->university, tokens[2]->finalGrade
			Student student(tokens[0], tokens[1], std::stod(tokens[2]));
			this->addStudent(student);
		}

		in.close();
	}

	std::vector<Student>& getAll() {
		return students;
	}

	~Repository() {
		writeInFile();
	}
};

//void testR() {
//	Repository repo = Repository("test.txt");
//	std::vector<Student>& s = repo.getAll();
//	assert(s.size() == 3);
//	assert(s.front().getName() == "Nicola Claudiu");
//	assert(s.front().getUniversity() == "UBB");
//	assert(s.front().getFinalGrade() == 10);
//	assert(s.back().getName() == "Toader Catalin");
//	assert(s.back().getUniversity() == "UTCN");
//	assert(s.back().getFinalGrade() == 6.4);
//	Student st("Test", "Usamv", 5.8);
//	repo.addStudent(st);
//	assert(s.size() == 4);
//	assert(s.back().getName() == "Test");
//	assert(s.back().getUniversity() == "Usamv");
//	assert(s.back().getFinalGrade() == 5.8);
//	repo.removeStudent(st);
//	assert(s.size() == 3);
//}
