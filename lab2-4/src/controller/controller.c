/*
 * controller.c
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#include <src/controller/controller.h>
#include <stdio.h>
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
	addItem(ctrl->repo, item);
}

DynamicVector* getAllAction(Controller* ctrl) {
	return ctrl->repo->vector;
}
void deleteAction(Controller* ctrl) {
}
void freeController(Controller* ctrl) {
}
