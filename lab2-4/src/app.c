/*
 ============================================================================
 Name        : lab2-4.c
 Author      : claudiu
 Version     :
 Copyright   : ubb
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <src/controller/controller.h>
#include <src/repository/repository.h>
#include <src/tests/tests.h>
#include <src/ui/ui.h>
#include <src/util/constants.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char* file = (char *) malloc(sizeof(char) * (strlen(FILENAME) + 1));
	file = FILENAME;
	Repository* repo = initRepository(file);
	Controller* ctrl = initController(repo);
	testAll();
	runUi(ctrl);
	destroyAll(ctrl);
	return EXIT_SUCCESS;
}
