/*
 * validator.h
 *
 *  Created on: Mar 8, 2016
 *      Author: claudiu
 */

#ifndef DOMAIN_VALIDATOR_H_
#define DOMAIN_VALIDATOR_H_

#include <src/domain/expense.h>

/**
 * Validate the item for have the fields of Expense struct.
 * Return an array of strings with invalid fileds.
 * item - Expense
 */
char** validateExpense(Expense* item);

/**
 * Get from first position in array of strings the numbers of errors
 * dereferenced the pointer to int an return
 * number - char*
 */
int getErrorsNumber(char** errors);

/**
 * Deallocate the memory of errors array
 * errors - char**
 */
void freeErrors(char** errors);

#endif /* DOMAIN_VALIDATOR_H_ */
