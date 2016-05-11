// BookstoreV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "BookstoreController.h"
#include "Validator.h"
#include "BookstoreRepository.h"
#include "tests.h"
#include "BookstoreConsole.h"
#include "BookstoreRepositoryFile.h"

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
int main()
{
	testAll();
	BookstoreRepositoryFile repository("Bookstore.txt");
	CartRepository repositoryCart(repository);
	BookValidator validator;
	CartValidator validatorCart;
	BookstoreController controller(repository, validator, repositoryCart, validatorCart);
	BookstoreConsole console(controller);

	//addSamples(controller);

	console.runApp();
    return 0;
}

