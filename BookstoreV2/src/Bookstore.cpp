//============================================================================
// Name        : Bookstore.cpp
// Author      : claudiu
// Version     :
// Copyright   : ubb
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "controller/BookstoreController.h"
#include "domain/Validator.h"
#include "repository/BookstoreRepository.h"
#include "tests/tests.h"
#include "ui/BookstoreConsole.h"

using namespace std;

void addSamples(BookstoreController& ctrl) {
	ctrl.add("Ion", "L. Rebreanu", "Roman", 1950);
	ctrl.add("Enigma Otiliei", "G. Calinescu", "Roman", 1900);
	ctrl.add("Moara cu Noroc", "I. Slavici", "Nuvela", 2011);
	ctrl.add("Mara	", "I. Slavici", "Nuvela", 1965);
	ctrl.add("Marile sperante", "C. Dickens", "Nuvela", 1800);
	ctrl.add("Mendebilul", "M. Cartarescu", "Roman", 2005);
	ctrl.add("Dama cu camelii", "A. Dumas", "Roman", 1800);
	ctrl.add("Decameronul", "G. Boccaccio", "Nuvela", 1200);

}

int main() {
	testAll();
	BookstoreRepository repository;
	CartRepository repositoryCart(repository);
	BookValidator validator;
	CartValidator validatorCart;
	BookstoreController controller(repository, validator, repositoryCart, validatorCart);
	BookstoreConsole console(controller);

	addSamples(controller);

	console.runApp();
}
