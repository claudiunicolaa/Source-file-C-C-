/*
 * tests.h
 *
 *  Created on: Mar 29, 2016
 *      Author: claudiu
 */

#ifndef TESTS_TESTS_H_
#define TESTS_TESTS_H_

#include <iostream>

#include "testBookstoreRepository.h"
#include "testCartRepository.h"


void testAll(){
	testBookstoreRepository();
	testCartRepository();
//	testBookstoreController();
//	testDynamicArray();
	cout << "Tests finised";
}


#endif /* TESTS_TESTS_H_ */
