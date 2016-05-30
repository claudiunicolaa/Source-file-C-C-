#pragma once
#include "CartRepository.h"
#include "BookstoreRepositoryFile.h"

class BookstoreRepositoryExportHTML
{
	CartRepository& repo;
	const string fileName;
	void writeToFile() {
		std::ofstream out(this->fileName, std::ios::trunc);
		if (!out.is_open()) {
			throw BookstoreRepositoryFileExceptions("Nu s-a putut deschide fisierul" + this->fileName + " pentru scriere");
		}
		out << "<html> <table>";
		for (auto& book : repo.getAll()) {
			out << "<tr> <td>" << book.getId() << "</td> <td>" << book.getTitle() << "</td> <td>" << book.getAuthor()
				<< "</td> <td>" << book.getSubject() << "</td> <td>" << book.getYear()
				<< "</td></tr>" << std::endl;
		}
		out << "</table> </html>";
		out.close();
	}
public:
	BookstoreRepositoryExportHTML(CartRepository& repo, string fileName) : repo(repo), fileName(fileName) {}
	void exportToHTML() {
		this->writeToFile();
	}
	~BookstoreRepositoryExportHTML() {}
};

