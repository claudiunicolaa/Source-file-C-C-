/*
 * ui.h
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#ifndef UI_UI_H_
#define UI_UI_H_

#include <src/controller/controller.h>

/**
 * The start of application
 * ctrl - Controller
 */
void runUi(Controller* ctrl);

/**
 * Put the menu in console
 */
void printMenu();

/**
 * Get the command from user.
 * Return an integer
 */
int getCommand();

/**
 * The add command get from console the properties
 * of expense
 * ctrl - Controller
 */
void addCommand(Controller* ctrl);

/**
 * Show the expenses
 * ctrl - Controller
 */
void showCommand(Controller* ctrl);

/**
 * The delete command remove from container an expense
 * ctrl - Controller
 */
void deleteCommand(Controller* ctrl);

/**
 * The update command read an id, show the expense (if exist)
 * and leave user to change the expense fields
 * ctrl - Controller
 */
void updateCommand(Controller* ctrl);

/**
 * Filter the vector by a property
 * ctrl - Controller
 */
void filterCommand(Controller* ctrl);

/**
 * Sort the vector by property asc and desc
 * ctrl - Controller
 */
void sortCommand(Controller* ctrl);

/**
 * Deallocate the memory from controller struct.
 * ctrl - Controller
 */
void destroyAll(Controller* ctrl);

#endif /* UI_UI_H_ */
