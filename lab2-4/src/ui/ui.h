/*
 * ui.h
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#ifndef UI_UI_H_
#define UI_UI_H_

#include <src/controller/controller.h>

void runUi(Controller* ctrl);
void printMenu();
int getCommand();
void addCommand(Controller* ctrl);
void showCommand(Controller* ctrl);
void deleteCommand(Controller* ctrl);
void destroyAll(Controller* ctrl);

#endif /* UI_UI_H_ */
