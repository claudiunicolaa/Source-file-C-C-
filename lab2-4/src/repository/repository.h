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

Repository* initRepository(char* fileName);
void addItem(Repository* repo, Expense* item);
int getLastId(Repository* repo);

/**
 * Read a line from a file and split after Expense fields (id, day, money, type)
 * file - FILE
 */
Expense* readLine(FILE* file);
DynamicVector* loadFile(Repository* repo);
void writeLine(FILE* file, Expense* item);
void writeFile(Repository* repo);
void deleteItem(Repository* repo, Expense* item);
void freeRepository(Repository* repo);
#endif /* REPOSITORY_REPOSITORY_H_ */
