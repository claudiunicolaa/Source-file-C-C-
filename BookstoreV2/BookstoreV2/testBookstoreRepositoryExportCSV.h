#pragma once
#include "BookstoreRepositoryExportCSV.h"

void testWriteToFile() {
	BookstoreRepositoryFile repo("test.txt");
	CartRepository cartR(repo);

	cartR.add(repo.getById(1));
	cartR.add(repo.getById(2));
	BookstoreRepositoryExportCSV repoE(cartR, "test.csv");
	
	repoE.exportToCSV();
}

void testBookstoreRepositoryExportCSV() {
	testWriteToFile();
}