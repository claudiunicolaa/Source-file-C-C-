#pragma once
#include "BookstoreRepositoryFile.h"
#include "CartRepository.h"
class BookstoreRepositoryExportCSV
{
	CartRepository& repo;
	const string fileName;

	void writeToFile() {
		std::ofstream out(this->fileName, std::ios::trunc);
		if (!out.is_open()) {
			throw BookstoreRepositoryFileExceptions("Nu s-a putut deschide fisierul" + this->fileName + " pentru scriere");
		}
		for (auto& book : repo.getAll()) {
			out << book.getId() << ',' << book.getTitle() << ',' << book.getAuthor()
				<< ',' << book.getSubject() << ',' << book.getYear()
				<< std::endl;
		}

		out.close();
	}
public:
	BookstoreRepositoryExportCSV(CartRepository& repo, string fileName) : repo(repo), fileName(fileName) {}

	void exportToCSV() {
		this->writeToFile();
	}

	~BookstoreRepositoryExportCSV() {}
};

