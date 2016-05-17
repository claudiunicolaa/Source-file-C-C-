/*
 * repository.h
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#ifndef REPOSITORY_REPOSITORY_H_
#define REPOSITORY_REPOSITORY_H_

#include <src/domain/expense.h>
#include <src/util/dynamicVector.h>
#include <stdio.h>

typedef struct {
	char* fileName;
	DynamicVector* vector;
} Repository;

/**
 * Constructor
 * fileName - char
 */
Repository* initRepository(char* fileName);

/**
 * Add an expense to vector.
 * repo - Repository
 * item - Expense
 */
void addItem(Repository* repo, Expense* item);

/**
 * Get the last id from vector.
 * repo - Repository
 */
int getLastId(Repository* repo);

/**
 * Read a line from a file and split after Expense fields (id, day, money, type)
 * file - FILE
 */
Expense* readLine(FILE* file);

/**
 * Read the vector from file
 * repo - Repository
 */
DynamicVector* loadFile(Repository* repo);

/**
 * Write a line in file
 * file - FILE
 * item - Expense
 */
void writeLine(FILE* file, Expense* item);

/**
 * Write the vector in file
 * repo - Repository
 */
void writeFile(Repository* repo);

/**
 * Delete an expense from vector
 * repo - Repository
 * item - Expense
 */
void deleteItem(Repository* repo, Expense* item);

/**
 * Deallocate the repository
 * repo - Repository
 */
void freeRepository(Repository* repo);
#endif /* REPOSITORY_REPOSITORY_H_ */
