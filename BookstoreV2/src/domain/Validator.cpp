/*
 * Validator.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#include "Validator.h"

#include <string>

using namespace std;

/*
 * Check if a string has just letters
 */
bool checkString(string s) {
	for (unsigned i = 0; i < s.length(); i++) {
		if (!isalpha(s[i]))
			return false;
	}
	return true;
}

void BookValidator::validate(Book book) throw (ValidatorException) {
	std::string err = "";
	if (book.getTitle() == "")
		throw ValidatorException("Carte trebuie sa aiba un titlu.");

	if (book.getAuthor() == "")
		throw ValidatorException("Carte trebuie sa aiba un autor.");

	if (book.getSubject() == "")
		throw ValidatorException("Carte trebuie sa aiba un subiect.");

	if (!checkString(book.getSubject()))
		throw ValidatorException("Genul carti trebuie sa contina doar litere.");

	if (book.getYear() < 1000 || book.getYear() > 2016)
		throw ValidatorException(
				"Anul trebuie sa fie cuprins intre 1000 si 2016");

}

void CartValidator::validate(const int n, const int nRepo)
		throw (ValidatorException) {
	if (n > nRepo) {
		throw ValidatorException("Nu sunt atatea carti in stoc");
	}
}
