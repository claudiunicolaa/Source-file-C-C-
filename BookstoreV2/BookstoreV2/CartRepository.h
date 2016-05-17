#pragma once
#include <vector>

#include "Book.h"
#include "BookstoreRepository.h"
#include <algorithm>
#include <random>    // std::default_random_engine
#include <chrono>    // std::chrono::system_clock

class CartRepository {
private:
	BookstoreRepository& repo;
public:
	vector<Book> cart;
	CartRepository(BookstoreRepository& repo) :
		repo(repo) {
	}

	/**
	* Empty the cart
	*/
	void empty();
	/**
	* Add a book to the cart
	*/
	void add(const Book);

	/**
	* Generate cart by a given number
	*/
	void generate(const int);

	/**
	* Get all elements of cart repository
	*/
	vector<Book>& getAll() {
		return cart;
	}

	/**
	*Get the size of cart
	*/
	int size() {
		return cart.size();
	}

	/**
	* Export the cart in a CSV file
	*/
	void exportToCSV();

	/**
	* Export the cart in a HTML file
	*/
	void exportToHTML();

	virtual ~CartRepository() {
	}
};

