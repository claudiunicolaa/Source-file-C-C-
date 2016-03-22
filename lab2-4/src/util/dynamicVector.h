/*
 * dynamicVector.h
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#ifndef UTIL_DYNAMICVECTOR_H_
#define UTIL_DYNAMICVECTOR_H_

typedef void* Item;

//Define a vector type
typedef struct {
	int capacity;	//total available slots
	int size;		//slots used
	Item *items;	//array of items we will storing

} DynamicVector;

/**
 * Initializes an empty array.
 * capacity - integer
 */
DynamicVector* initDynamicVector(int capacity);

/**
 * Add an item in DynamicVector.
 * vector - DynamicVector
 * item - Item
 */
void add(DynamicVector* vector, Item item);

/**
 * Delete an item from DynamicVector.
 * vector - DynamicVector
 * item - Item
 */
void delete(DynamicVector* vector, Item item);

/**
 * Return an item of position.
 * vector - DynamicVector
 * position - integer
 */
Item findByPosition(DynamicVector* vector, int position);

/**
 * Return the size of DynamicVector.
 * vector - DynamicVector
 */
int getSize(DynamicVector* vector);

/**
 * Print the items of vector
 * vector - DynamicVector
 */
void printDynamicVector(DynamicVector* vector);

/**
 * Destroy an item
 * vector - DynamicVector
 * position - integer
 */
void destroyByPosition(DynamicVector* vector, int position);

/**
 * Get the last item of vector
 */
Item getLastItem(DynamicVector* vector);

/**
 * Copy the dynamic vector
 * sourceVector - DynamicVector
 */
DynamicVector* copyDynamicVector(DynamicVector* sourceVector);

/**
 * Memory free.
 * vector - DynamicVector
 */
void destroyDynamicVector(DynamicVector* vector);

#endif /* UTIL_DYNAMICVECTOR_H_ */
