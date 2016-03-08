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
} Controller;

Controller* initController(Repository* repo);
void addAction(Controller* ctrl, int day, float money, char* type);
DynamicVector* getAllAction(Controller* ctrl);
void deleteAction(Controller* ctrl);
void freeController(Controller* ctrl);
#endif /* CONTROLLER_CONTROLLER_H_ */
