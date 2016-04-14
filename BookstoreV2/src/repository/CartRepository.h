/*
 * CartRepository.h
 *
 *  Created on: Apr 12, 2016
 *      Author: claudiu
 */

#ifndef REPOSITORY_CARTREPOSITORY_H_
#define REPOSITORY_CARTREPOSITORY_H_

#include <vector>

#include "../domain/Book.h"
#include "../repository/BookstoreRepository.h"
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

	int size(){
		return cart.size();
	}

	virtual ~CartRepository() {
	}
};

#endif /* REPOSITORY_CARTREPOSITORY_H_ */
