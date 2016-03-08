/*
 * repository.c
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#include <src/repository/repository.h>
#include <src/util/constants.h>
#include <src/util/dynamicVector.h>
#include <stdlib.h>
#include <string.h>

Repository* initRepository(char* fileName) {
	Repository* repo = (Repository*) malloc(sizeof(Repository));
	repo->fileName = (char*) malloc(sizeof(char) * strlen(fileName) + 1);
	strcpy(repo->fileName, fileName);
	repo->vector = initDynamicVector(50);
//	repo->vector = loadFile(repo);
	return repo;
}
void addItem(Repository* repo, Expense* item) {
	add(repo->vector, item);
}

int getLastId(Repository* repo) {
	int id = 0;
	id = getSize(repo->vector);
//	FILE* file;
//	file = fopen(repo->fileName, "r");
//	fseek(file, -LINE_LENGTH, SEEK_END);
//	Expense* item;
//	item = readLine(file);
//	fclose(file);
//	id = item->id + 1;
	return id;
}

/**
 * Read a line from a file and split after Expense fields (id, day, money, type)
 * file - FILE
 */
Expense* readLine(FILE* file) {
	Expense* item;
	char* line, *token;
	int id;
	int day;
	float money;
	line = (char*) malloc(sizeof(char) * LINE_LENGTH);
	if (fgets(line, LINE_LENGTH, file) == NULL) {
		item = NULL;
		return item;
	}
	token = strtok(line, "#");
	id = atoi(token);
	token = strtok(NULL, "#");
	day = atoi(token);
	token = strtok(NULL, "#");
	money = atof(token);
	token = strtok(NULL, "\n");
	item = initExpense(id, day, money, token);
	return item;
}
void loadFile(Repository* repo) {
	FILE* file;
	char* line;
	file = fopen(repo->fileName, "r");
	line = malloc(sizeof(char) * 50);
	fgets(line, 50, file);
	fclose(file);
}
void deleteItem(Repository* repo, Expense* item) {
}
void freeRepository(Repository* repo) {
}
