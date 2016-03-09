/*
 * testDynamicVector.c
 *
 *  Created on: Mar 10, 2016
 *      Author: claudiu
 */

#include <assert.h>
#include <src/repository/repository.h>
#include <src/tests/testDynamicVector.h>
#include <src/util/dynamicVector.h>
#include <stdio.h>

/**
 * Call all tests of DynamicVector
 */
void testDynamicArray() {
	testInitDynamicVector();
	testAdd();
	testDelete();
	testFindByPosition();
	testGetSize();
	printf("Tests finish.");
}

/**
 * Initializes the DynamicVector to use in tests
 */
DynamicVector* setUp() {
	DynamicVector* vector = initDynamicVector(20);
	return vector;
}

/**
 * Free memory after tests.
 */
void tearDown(DynamicVector* testVector) {
//	destroyDynamicVector(testVector);
}

/**
 * Test the initialization of an empty array.
 */
void testInitDynamicVector() {
	//init dynamic vector
	int capacity = 10;
	DynamicVector* vector = initDynamicVector(capacity);
	//test capacity
	assert(vector->capacity == 10);
	//test size
	assert(vector->size == 0);
	//test items
	assert(vector->items != NULL);
	//destroy
	tearDown(vector);
}

/**
 * Test the add operation

 */
void testAdd() {
	//set up
	DynamicVector* vector = setUp();
	//add item
	int it = 2;
	add(vector, &it);
	//test if was added findByPosition
	assert((*(int*) findByPosition(vector, 0)) == 2);
	//add item
	char it2[3] = "abC";
	add(vector, &it2);

	//test if was added with size
	assert(vector->size == 2);
	//destroy
	tearDown(vector);
}

/**
 * Test the delete of an item from DynamicVector.

 */
void testDelete() {
	//set up
	DynamicVector* vector = setUp();
	//add few items
	int it1 = 0;
	int it2 = 1;
	int it3 = 2;
	int it4 = 3;
	add(vector, &it1);
	add(vector, &it2);
	add(vector, &it3);
	add(vector, &it4);
	//delete one
	delete(vector, &it3);
	//test if was deleted
	assert(vector->size == 3);
	//destroy
	tearDown(vector);
}

/**
 * Test the find operation of an item by position.

 */
void testFindByPosition() {
	//set up
	DynamicVector* vector = setUp();
	//add a item
	int it = 1000;
	add(vector, &it);
	//test if find on position 0
	assert((*(int *) findByPosition(vector, 0)) == 1000);
	//destroy
	tearDown(vector);
}

/**
 * Test the operation to get the size of DynamicVector.

 */
void testGetSize() {
	//set up
	DynamicVector* vector = setUp();
	//add 4 items
	int it1 = 0;
	int it2 = 1;
	int it3 = 2;
	int it4 = 3;
	add(vector, &it1);
	add(vector, &it2);
	add(vector, &it3);
	add(vector, &it4);
	//test if size is 4
	assert(vector->size == 4);
	//delete 2
	delete(vector, &it1);
	delete(vector, &it2);
	//test if size is 2
	assert(vector->size == 2);
	//destroy
	tearDown(vector);
}
