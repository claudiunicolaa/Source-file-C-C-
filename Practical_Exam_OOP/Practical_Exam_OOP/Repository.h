#pragma once

#include "Nota.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "MyExceptions.h"
#include "Observer.h"
#include <assert.h>

class Repository :public Observable {
private:
	std::vector<Nota> note;
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
	void addNota(const Nota& nota) {
		this->note.push_back(nota);
		notify();
	}

	/*
	Remove an Nota
	*/
	void removeNota(Nota& nota) {
		for (auto it = this->note.begin(); it != this->note.end(); ++it) {
			auto current = *it;
			if (current == nota) {
				this->note.erase(it);
				return;
			}
		}
		notify();
	}
	/*
	Write in file
	*/
	void writeInFile() {
		std::ofstream out(this->fileName);
		if (!out.is_open()) {
			throw RepoExceptions("Error: Can not open the file(" + this->fileName + ")");
		}

		for (auto& nota : this->note) {
			out << nota.getStudent() << '|' << nota.getValoare()
				<< '|' << nota.getProfesor() << std::endl;
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
			//tokens[0]->student, tokens[1]->valoare, tokens[2]->profesor
			Nota nota(tokens[0], std::stof(tokens[1]), tokens[2]);
			this->addNota(nota);
		}

		in.close();
	}

	std::vector<Nota>& getAll() {
		return note;
	}

	std::vector<Nota> getAllByValoare() {

		sort(note.begin(), note.end(),
			[](Nota& n1, Nota& n2) {return n1.getValoare() < n2.getValoare(); });

		return note;
	}

	bool existStudent(std::string student) {
		for (auto it = note.begin(); it != note.end(); ++it) {
			auto current = *it;
			if (current.getStudent() == student)
				return true;
		}
		return false;
	}

	std::vector<std::string> getProfi() {
		std::vector<std::string> profi;
		for (auto it = note.begin(); it != note.end(); ++it) {
			bool ok = true;
			auto curent = *it;
			for (auto i = profi.begin(); i != profi.end(); ++i) {
				auto curent2 = *i;
				if (curent.getProfesor() == curent2) {
					ok = false;
					break;
				}
			}
			if (ok) {
				profi.push_back(curent.getProfesor());
			}
		}

		return profi;
	}

	std::vector<float> getNote(std::string profesor) {
		std::vector<float> n;
		for (auto it = note.begin(); it != note.end(); ++it) {
			auto curent = *it;
			if (curent.getProfesor() == profesor) {
				n.push_back(curent.getValoare());
			}
		}

		return n;
	}

	~Repository() {
		writeInFile();
	}
};

//void testR() {
//	Repository repo = Repository("test.txt");
//	std::vector<Nota>& s = repo.getAll();
//	assert(s.size() == 3);
//	assert(s.front().getStudent() == "Nicola Claudiu");
//	assert(s.front().getValoare() == 9.7);
//	assert(s.front().getProfesor() == "Istvan");
//	assert(s.back().getStudent() == "Onciou Costin");
//	assert(s.back().getProfesor() == "Iuliana");
//	assert(s.back().getValoare() == 9);
//	Nota st("Test", 5.8, "Usamv");
//	repo.addNota(st);
//	assert(s.size() == 4);
//}