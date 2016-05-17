#pragma once
#include "BookstoreRepositoryExportHTML.h"
void testExportToHtml() {
	BookstoreRepositoryFile repo("test.txt");
	CartRepository cartR(repo);

	cartR.add(repo.getById(1));
	cartR.add(repo.getById(2));
	BookstoreRepositoryExportHTML repoE(cartR, "test.htm");

	repoE.exportToHTML();
}

void testBookstoreRepositoryExportHTML() {
	testExportToHtml();
}