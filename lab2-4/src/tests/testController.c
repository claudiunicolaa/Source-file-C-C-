/*
 * testController.c
 *
 *  Created on: Mar 16, 2016
 *      Author: claudiu
 */

#include <src/controller/controller.h>
#include <src/repository/repository.h>
#include <src/tests/testDynamicVector.h>
#include <src/ui/ui.h>
#include <src/util/dynamicVector.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * Initializes the DynamicVector to use in tests
 */
Controller* setUpC() {
	char* file = (char *) malloc(sizeof(char) * (strlen("test.txt") + 1));
	file = "test.txt";
	Repository* repo = initRepository(file);
	Controller* ctrl = initController(repo);
	return ctrl;
}

void tearDownC(Controller* ctrl) {
	destroyAll(ctrl);
}

/**
 * Test the undo functionality
 */
void testUndo() {
	Controller* ctrl = setUpC();
	addAction(ctrl, 9, 100, "mancare");
//	delete(ctrl->repo->vector, &it3);
	undo(ctrl);
	assert((int )ctrl->undoVector->size == 3);
}

/**
 * Call all tests
 */
void testController() {
	testUndo();
}

