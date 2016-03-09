/*
 * controller.c
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#include <src/controller/controller.h>
#include <src/domain/expense.h>
#include <src/domain/validator.h>
#include <stdlib.h>

/**
 * Constructor
 * repo - Repository
 */
Controller* initController(Repository* repo) {
	Controller* ctrl = (Controller*) malloc(sizeof(Controller));
	ctrl->repo = repo;
	return ctrl;
}

/**
 * Create and Expense item and validate. If it's ok call
 * the repository to save expense.
 * ctrl - Controller
 * day - int
 * money - float
 * type - char*
 */
void addAction(Controller* ctrl, int day, float money, char* type) {
	int id = 0;
	id = getLastId(ctrl->repo);
	Expense* item = initExpense(id, day, money, type);
	ctrl->valid = validateExpense(item);
	if (getErrorsNumber(ctrl->valid) > 0) {
		destroyExpense(item);
		return;
	} else
		addItem(ctrl->repo, item);
}

/**
 * Get the vector.
 * ctrl - Controller
 */
DynamicVector* getAllAction(Controller* ctrl) {
	return ctrl->repo->vector;
}

/**
 * Write the vector in file
 * ctrl - Controller
 */
void writeAll(Controller* ctrl) {
	writeFile(ctrl->repo);
}

/**
 * If id exist call the repository to delete the expense.
 * ctrl - Controller
 * id - int
 */
int deleteAction(Controller* ctrl, int id) {
	int search = searchId(ctrl, id);
	if (search > -1)
		deleteItem(ctrl->repo, findByPosition(ctrl->repo->vector, search));
	return search;
}

/**
 * Update an item.
 * ctrl - Controller
 * id - int
 * positon - int
 * day - int
 * money - float
 * type - char*
 */
void updateAction(Controller* ctrl, int id, int position, int day, float money,
		char* type) {
	Expense* newItem = initExpense(id, day, money, type);
	ctrl->valid = validateExpense(newItem);
	if (getErrorsNumber(ctrl->valid) > 0) {
		destroyExpense(newItem);
		return;
	} else {
		deleteItem(ctrl->repo, findByPosition(ctrl->repo->vector, position));
		addItem(ctrl->repo, newItem);
	}
}

/**
 * Search an id in vector.
 * Return the positon if exist, otherwise -1
 * ctrl - Controller
 * id - int
 */
int searchId(Controller* ctrl, int id) {
	int i = 0;
	Expense* item;
	DynamicVector* vector = getAllAction(ctrl);
	for (i = 0; i < getSize(vector); i++) {
		item = findByPosition(vector, i);
		if (item->id == id) {
			return i;
		}
	}
	return -1;
}

/**
 * Deallocate the memory of controller
 * ctrl - Controller
 */
void freeController(Controller* ctrl) {
	free(ctrl);
}
