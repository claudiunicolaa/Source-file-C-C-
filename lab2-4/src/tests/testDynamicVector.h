/*
 * testDynamicVector.h
 *
 *  Created on: Mar 10, 2016
 *      Author: claudiu
 */

#ifndef TESTS_TESTDYNAMICVECTOR_H_
#define TESTS_TESTDYNAMICVECTOR_H_

#include <src/util/dynamicVector.h>

/**
 * Call all tests of DynamicVector
 */
void testDynamicArray();

/**
 * Initializes the DynamicVector to use in tests
 */
DynamicVector* setUp();

/**
 * Free memory after tests.
 */
void tearDown(DynamicVector* testVector);

/**
 * Test the initialization of an empty array.
 */
void testInitDynamicVector();

/**
 * Test the add operation

 */
void testAdd();

/**
 * Test the delete of an item from DynamicVector.

 */
void testDelete();

/**
 * Test the find operation of an item by position.

 */
void testFindByPosition();

/**
 * Test the operation to get the size of DynamicVector.

 */
void testGetSize();

/**
 * Test the copy operation
 */
void testCopyDynamicVector();
#endif /* TESTS_TESTDYNAMICVECTOR_H_ */
