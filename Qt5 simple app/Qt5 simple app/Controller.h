#pragma once
#include <assert.h>
#include "Repository.h"

class Controller {
private:
	Repository &repo;
	StudentValidator &validator;

public:
	Controller(Repository& repo, StudentValidator& validator) : repo(repo), validator(validator) {
	}

	void add(const std::string name, std::string university, double finalGrade) {
		Student student(name, university, finalGrade);
		validator.validate(student);
		repo.addStudent(student);
	}

	void remove(const std::string name, std::string university, double finalGrade) {
		Student student(name, university, finalGrade);
		validator.validate(student);
		repo.removeStudent(student);
	}

	void update(const std::string name, std::string university, double finalGrade,
		const std::string newName, std::string newUniversity, double newFinalGrade) {
		Student oldStudent(name, university, finalGrade);
		Student newStudent (newName, newUniversity, newFinalGrade);
		repo.updateStudent(oldStudent, newStudent);
	}

	std::vector<Student>& getAll() {
		return repo.getAll();
	}

	~Controller() {
	}
};

//void testC() {
//	Repository repo("test.txt");
//	StudentValidator valid;
//	Controller ctrl(repo, valid);
//	
//	ctrl.add("Ionut F", "ioi", 7.6);
//	assert(ctrl.getAll().size() == 4);
//	assert(ctrl.getAll().back().getName() == "Ionut F");
//	assert(ctrl.getAll().back().getUniversity() == "ioi");
//	assert(ctrl.getAll().back().getFinalGrade() == 7.6);
//
//	ctrl.update("Ionut F", "ioi", 7.6, "Florin F", "mit", 9.6);
//	assert(ctrl.getAll().size() == 4);
//	assert(ctrl.getAll().back().getName() == "Florin F");
//	assert(ctrl.getAll().back().getUniversity() == "mit");
//	assert(ctrl.getAll().back().getFinalGrade() == 9.6);
//	
//	ctrl.remove("Florin F", "mit", 9.6);
//	assert(ctrl.getAll().size() == 3);
//}