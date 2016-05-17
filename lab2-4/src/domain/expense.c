/*
 * expense.c
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#include <math.h>
#include <src/domain/expense.h>
#include <stdlib.h>
#include <string.h>

/**
 * Construct
 * id - int
 * day - int
 * money - float
 * type - char*
 */
Expense* initExpense(int id, int day, float money, char* type) {
	Expense* item = (Expense*) malloc(sizeof(Expense));
	item->id = id;
	item->day = day;
	item->money = fabs(money);
	item->type = (char*) malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(item->type, type);
	return item;
}

/**
 * Get the money
 * item - Expense
 */
float getMoney(Expense* item) {
	return item->money;
}

/**
 * Get the type
 * item - Expense
 */
char* getType(Expense* item) {
	return item->type;
}

/**
 * Destructor
 * item - Expense
 */
void destroyExpense(Expense* item) {
	free(item->type);
	free(item);
}
