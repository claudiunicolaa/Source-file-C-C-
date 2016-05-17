/*
 * tests.c
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#include <src/tests/testController.h>
#include <src/tests/testDynamicVector.h>


void testAll() {
	testDynamicArray();
	testController();
	printf("Tests finish.");
}
