#pragma once
#include <string>

class Nota {
private:
	std::string student;
	float valoare;
	std::string profesor;
public:
	/*
		Constructor default
	*/
	Nota() {
		this->student = "";
		this->valoare = 0;
		this->profesor = "";
	}

	/*
		Constructor cu 3 parametrii
	*/
	Nota(std::string student, float nota, std::string profesor) {
		this->student = student;
		this->valoare = nota;
		this->profesor = profesor;
	}

	/*
		Constructor de copiere
	*/
	Nota(const Nota& other) {
		this->student = other.student;
		this->valoare = other.valoare;
		this->profesor = other.profesor;
	}

	/*
		Suprascrie operatorul =
		nota1 = nota2 => nota2 va fi copiat in nota1
	*/
	Nota& operator=(const Nota& other) {
		if (this != &other) {
			this->student = other.student;
			this->valoare = other.valoare;
			this->profesor = other.profesor;
		}
		return *this;
	}

	/*
		Suprascrie operatorul ==
	*/
	bool operator==(Nota& other) {

		if (this->student != other.getStudent()) {
			return false;
		}

		if (this->valoare != other.getValoare()) {
			return false;
		}

		if (this->profesor != other.getProfesor()) {
			return false;
		}

		return true;
	}

	std::string getStudent() {
		return this->student;
	}

	float getValoare() {
		return this->valoare;

	}
	std::string getProfesor() {
		return this->profesor;
	}

	void setStudent(std::string student) {
		this->student = student;
	}

	void setValoare(float valoare) {
		this->valoare = valoare;
	}

	void setProfesor(std::string profesor) {
	}

	~Nota() {
	}

	friend std::ostream& operator<<(std::ostream& os, const Nota& nota) {
		os << nota.student << " " << nota.valoare << " " << nota.profesor;

		return os;
	}
};