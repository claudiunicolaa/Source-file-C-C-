/*
 * controller.h
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <src/repository/repository.h>
#include <src/util/dynamicVector.h>

typedef struct {
	Repository* repo;
	char** valid;
} Controller;

/**
 * Constructor
 * repo - Repository
 */
Controller* initController(Repository* repo);

/**
 * Create and Expense item and validate. If it's ok call
 * the repository to save expense.
 * ctrl - Controller
 * day - int
 * money - float
 * type - char*
 */
void addAction(Controller* ctrl, int day, float money, char* type);

/**
 * Get the vector.
 * ctrl - Controller
 */
DynamicVector* getAllAction(Controller* ctrl);

/**
 * Write the vector in file
 * ctrl - Controller
 */
void writeAll(Controller* ctrl);

/**
 * If id exist call the repository to delete the expense.
 * ctrl - Controller
 * id - int
 */
int deleteAction(Controller* ctrl, int id);

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
		char* type);

/**
 * Search an id in vector.
 * Return the positon if exist, otherwise -1
 * ctrl - Controller
 * id - int
 */
int searchId(Controller* ctrl, int id);

/**
 * Filter the vector by money property
 * ctrl - Controller
 * money - float
 */
DynamicVector* filterByMoney(Controller* ctrl, float money);
/**
 * Filter the vector by day property
 * ctrl - Controller
 * day - int
 */
DynamicVector* filterByDay(Controller* ctrl, int day);
/**
 * Filter the vector by type property
 * ctrl - Controller
 * type - char*
 */
DynamicVector* filterByType(Controller* ctrl, char* type);

/**
 * Deallocate the memory of controller
 * ctrl - Controller
 */
void freeController(Controller* ctrl);
#endif /* CONTROLLER_CONTROLLER_H_ */
