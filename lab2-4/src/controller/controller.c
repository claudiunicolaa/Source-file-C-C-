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

Controller* initController(Repository* repo) {
	Controller* ctrl = (Controller*) malloc(sizeof(Controller));
	ctrl->repo = repo;
	return ctrl;
}
void addAction(Controller* ctrl, int day, float money, char* type) {
	int id = 0;
	id = getLastId(ctrl->repo);
	Expense* item = initExpense(id, day, money, type);
	ctrl->valid = validateExpense(item);
	if (getErrorsNumber(ctrl->valid) > 1) {
		destroyExpense(item);
		return;
	} else
		addItem(ctrl->repo, item);
}

DynamicVector* getAllAction(Controller* ctrl) {
	return ctrl->repo->vector;
}

void writeAll(Controller* ctrl) {
	writeFile(ctrl->repo);
}
int deleteAction(Controller* ctrl, int id) {
	int ok = 0;
	int i = 0;
	Expense* item;
	DynamicVector* vector = getAllAction(ctrl);
	for (i = 0; i < getSize(vector); i++) {
		item = findByPosition(vector, i);
		if (item->id == id) {
			ok = 1;
			deleteItem(ctrl->repo, item);
			break;
		}
	}
	return ok;

}
void freeController(Controller* ctrl) {
	free(ctrl);
}
