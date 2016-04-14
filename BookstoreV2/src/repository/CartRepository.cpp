/*
 * CartRepository.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: claudiu
 */

#include "CartRepository.h"

void CartRepository::empty() {
	cart.clear();
}

void CartRepository::add(const Book book) {
	cart.push_back(book);
}

void CartRepository::generate(const int number) {
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	vector<Book> all = repo.getAll();
	std::shuffle(all.begin(), all.end(), std::default_random_engine(seed));
	while (cart.size() < number && all.size() > 0) {
		cart.push_back(all.back());
		all.pop_back();
	}
}



