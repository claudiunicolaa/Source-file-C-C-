/*
 * validate.c
 *
 *  Created on: Mar 8, 2016
 *      Author: claudiu
 */

#include <src/domain/expense.h>
#include <stdlib.h>
#include <string.h>

/**
 * Validate the item for have the fields of Expense struct
 * item - Expense
 */
char** validateExpense(Expense* item) {
	char** errors = (char**) malloc(sizeof(char*) * 3);
	int e = 0;
	if (item->day < 1 || item->day > 31) {
		e++;
		errors[e] = (char*) malloc(sizeof(char) * 40);
		errors[e] = "Ziua trebuie sa fie intre 1 si 31";
	}
	char types[] = "mancare,transport,tv&internet,imbracaminte,altele,";
	char* type = (char*) malloc(sizeof(char) * (strlen(item->type) + 1));
	strcpy(type, item->type);
	strcat(type, ",");
	if (strstr(types, type) == NULL) {
		e++;
		errors[e] = (char*) malloc(sizeof(char) * 40);
		errors[e] = "Tipul trebuie sa fie cele mentionate";
	}
	free(type);
	errors[0] = (char*) malloc(sizeof(char) * 1);
	errors[0] = (char) e;
	return errors;
}

/**
 * Get from first position in array of strings the numbers of errors
 * dereferenced the pointer to int an return
 * number - char*
 */
int getErrorsNumber(char** errors) {
	return (int*) errors[0];
}

/**
 * Deallocate the memory of errors array
 * errors - char**
 */
void freeErrors(char** errors) {
	int i = 0;
	for (i = 1; i < getErrorsNumber(errors); i++) {
		free(errors[i]);
	}
	free(errors[0]);
	free(errors);
}
