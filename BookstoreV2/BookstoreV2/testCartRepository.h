#pragma once
#include <cassert>
#include <vector>

#include "Book.h"
#include "CartRepository.h"

void testEmpty() {
	BookstoreRepository repo;
	CartRepository cr(repo);
	Book b = Book(1, "Ion", "L. Rebreanu", "Roman", 1950);
	cr.add(b);

	cr.empty();
	assert(cr.cart.size() == 0);

}
void testAdd() {
	BookstoreRepository repo;
	CartRepository cr(repo);
	Book b = Book(1, "Ion", "L. Rebreanu", "Roman", 1950);
	cr.add(b);
	b = Book(2, "Enigma Otiliei", "G. Calinescu", "Roman", 1900);
	cr.add(b);
	b = Book(3, "Moara cu Noroc", "I. Slavici", "Nuvela", 2011);
	cr.add(b);
	b = Book(4, "Mara	", "I. Slavici", "Nuvela", 1965);
	cr.add(b);
	b = Book(5, "Marile sperante", "C. Dickens", "Nuvela", 1800);
	cr.add(b);
	b = Book(6, "Mendebilul", "M. Cartarescu", "Roman", 2005);
	cr.add(b);
	b = Book(7, "Dama cu camelii", "A. Dumas", "Roman", 1800);
	cr.add(b);
	b = Book(8, "Decameronul", "G. Boccaccio", "Nuvela", 1200);
	cr.add(b);
	assert(cr.cart.size() == 8);
}
void testGenerate() {
	BookstoreRepository repo;
	Book b = Book(1, "Ion", "L. Rebreanu", "Roman", 1950);
	repo.addBook(b);
	b = Book(2, "Enigma Otiliei", "G. Calinescu", "Roman", 1900);
	repo.addBook(b);
	b = Book(3, "Moara cu Noroc", "I. Slavici", "Nuvela", 2011);
	repo.addBook(b);
	b = Book(4, "Mara	", "I. Slavici", "Nuvela", 1965);
	repo.addBook(b);
	b = Book(5, "Marile sperante", "C. Dickens", "Nuvela", 1800);
	repo.addBook(b);
	b = Book(6, "Mendebilul", "M. Cartarescu", "Roman", 2005);
	repo.addBook(b);
	b = Book(7, "Dama cu camelii", "A. Dumas", "Roman", 1800);
	repo.addBook(b);
	b = Book(8, "Decameronul", "G. Boccaccio", "Nuvela", 1200);
	repo.addBook(b);
	CartRepository cr(repo);
	cr.generate(6);
	assert(cr.cart.size() == 6);
}

void testCartRepository() {
	testEmpty();
	testAdd();
	testGenerate();
}