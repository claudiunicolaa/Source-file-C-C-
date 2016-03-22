/*
 * controller.c
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#include <math.h>
#include <src/controller/controller.h>
#include <src/domain/expense.h>
#include <src/domain/validator.h>
#include <stdlib.h>
#include <string.h>

/**
 * Constructor
 * repo - Repository
 */
Controller* initController(Repository* repo) {
	Controller* ctrl = (Controller*) malloc(sizeof(Controller));
	ctrl->repo = repo;
	ctrl->undoVector = initDynamicVector(50);
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
	} else {
		ctrl->undoVector = copyDynamicVector(ctrl->repo->vector);
		addItem(ctrl->repo, item);
	}
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
		ctrl->undoVector = copyDynamicVector(ctrl->repo->vector);
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
		ctrl->undoVector = copyDynamicVector(ctrl->repo->vector);
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
 * Filter the vector by money property
 * ctrl - Controller
 * money - float
 */
DynamicVector* filterByMoney(Controller* ctrl, float money) {
	DynamicVector* filteredVector = initDynamicVector(
			ctrl->repo->vector->size + 1);
	Expense* item;
	int i = 0;
	for (i = 0; i < getSize(ctrl->repo->vector); i++) {
		item = findByPosition(ctrl->repo->vector, i);
		if (fabs(item->money - money) < 0.001) {
			add(filteredVector, item);
		}
	}
	return filteredVector;
}

/**
 * Filter the vector by day property
 * ctrl - Controller
 * day - int
 */
DynamicVector* filterByDay(Controller* ctrl, int day) {
	DynamicVector* filteredVector = initDynamicVector(
			ctrl->repo->vector->size + 1);
	Expense* item;
	int i = 0;
	for (i = 0; i < getSize(ctrl->repo->vector); i++) {
		item = findByPosition(ctrl->repo->vector, i);
		if (fabs(item->day - day) == 0) {
			add(filteredVector, item);
		}
	}
	return filteredVector;
}

/**
 * Filter the vector by type property
 * ctrl - Controller
 * type - char*
 */
DynamicVector* filterByType(Controller* ctrl, char* type) {
	DynamicVector* filteredVector = initDynamicVector(
			ctrl->repo->vector->size + 1);
	Expense* item;
	int i = 0;
	for (i = 0; i < getSize(ctrl->repo->vector); i++) {
		item = findByPosition(ctrl->repo->vector, i);
		if (strcmp(item->type, type) == 0) {
			add(filteredVector, item);
		}
	}
	return filteredVector;
}

/**
 *
 */
int compareMoneyAsc(const void* a, const void* b) {
	Expense* pa = *(Expense**) a;
	Expense* pb = *(Expense**) b;
	return getMoney(pb) - getMoney(pa);
}

/**
 *
 */
int compareMoneyDesc(const void* a, const void* b) {
	Expense* pa = *(Expense**) a;
	Expense* pb = *(Expense**) b;
	return getMoney(pa) - getMoney(pb);
}

/**
 * Sort the vector by money property
 * ctrl - Controller
 * money - float
 */
DynamicVector* sortByMoney(Controller* ctrl, char* order) {
	DynamicVector* sortedVector = getAllAction(ctrl);
	int (*compare)(const void*a, const void* b);
	if (strcmp(order, "asc")) {
		compare = compareMoneyAsc;
	} else if (strcmp(order, "desc")) {
		compare = compareMoneyDesc;
	}
	qsort(sortedVector->items, sortedVector->size, sizeof(Expense*), compare);
	return sortedVector;
}

/**
 *
 */
int compareTypeAsc(const void* a, const void* b) {
	Expense* pa = *(Expense**) a;
	Expense* pb = *(Expense**) b;
	return strcmp(getType(pb), getType(pa));
}

/**
 *
 */
int compareTypeDesc(const void* a, const void* b) {
	Expense* pa = *(Expense**) a;
	Expense* pb = *(Expense**) b;
	return strcmp(getType(pa), getType(pb));
}

/**
 * Sort the vector by type propery
 * ctrl - Controller
 * type - char*
 */
DynamicVector* sortByType(Controller* ctrl, char* order) {
	DynamicVector* sortedVector = getAllAction(ctrl);
	int (*compare)(const void*a, const void* b);
	if (strcmp(order, "asc")) {
		compare = compareTypeAsc;
	} else if (strcmp(order, "desc")) {
		compare = compareTypeDesc;
	}
	qsort(sortedVector->items, sortedVector->size, sizeof(Expense*), compare);
	return sortedVector;
}

/**
 *Undo functionality. Destroy the current vector
 * and copy in her the oldest vector.
 * ctrl - Controller
 * vector - DynamicVector
 */
void undo(Controller* ctrl) {
	if (getSize(ctrl->undoVector) > 0) {
		ctrl->repo->vector = copyDynamicVector(ctrl->undoVector);
		delete(ctrl->undoVector, getLastItem(ctrl->undoVector));
	}
}

/**
 * Deallocate the memory of controller
 * ctrl - Controller
 */
void freeController(Controller* ctrl) {
	free(ctrl);
}
