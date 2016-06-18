#pragma once

#include "Repository.h"


class Controller {
private:
	Repository &repo;
	NotaValidator &validator;
public:
	Controller(Repository& repo, NotaValidator& validator) : repo(repo), validator(validator) {
	}
	
	std::vector<Nota>& getAll() {
		return repo.getAll();
	}

	std::vector<Nota> getAllByValoare() {
		return repo.getAllByValoare();
	}

	void add(std::string student, float valoare, std::string profesor) {
		Nota nota(student, valoare, profesor);
		if (repo.existStudent(student)) {
			throw Validator("Studentul deja exista");
		}
		validator.validate(nota);
		repo.addNota(nota);
	}

	Repository& getRepo() {
		return repo;
	}

	std::vector<std::string> getProfesori() {
		return repo.getProfi();
	}

	~Controller() {
	}
};

//void testC() {
//	Repository repo("test.txt");
//	NotaValidator valid;
//	Controller ctrl(repo, valid);
//	
//	ctrl.add("Ionut F", 7.6, "Gabi");
//	assert(ctrl.getAll().size() == 4);
//	assert(ctrl.getAll().back().getStudent() == "Ionut F");
//	assert(ctrl.getAll().back().getProfesor() == "Gabi");
//	assert(ctrl.getAll().back().getValoare() == 7.6);
//}