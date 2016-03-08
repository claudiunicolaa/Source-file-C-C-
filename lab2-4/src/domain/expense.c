/*
 * expense.c
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#include <src/domain/expense.h>
#include <stdlib.h>
#include <string.h>

Expense* initExpense(int id, int day, float money, char* type) {
	Expense* item = (Expense*) malloc(sizeof(Expense));
	item->id = id;
	item->day = day;
	item->money = money;
	item->type = (char*) malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(item->type, type);
	return item;
}
