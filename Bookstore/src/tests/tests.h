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


void testAll(){
	testBookstoreRepository();
//	testBookstoreController();
//	testDynamicArray();
	cout << "Tests finised";
}


#endif /* TESTS_TESTS_H_ */
