#include "stdafx.h"
#include "CartRepository.h"
#include "BookstoreRepositoryFile.h"

void CartRepository::empty() {
	cart.clear();
}

void CartRepository::add(const Book book) {
	cart.push_back(book);
}

void CartRepository::generate(const int number) {
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	vector<Book> all = repo.getAll();
	std::shuffle(all.begin(), all.end(), std::default_random_engine(seed));
	while (cart.size() < number && all.size() > 0) {
		cart.push_back(all.back());
		all.pop_back();
	}
}

void CartRepository::exportToHTML() {
	std::ofstream out("export.html", std::ios::trunc);
	if (!out.is_open()) {
		throw BookstoreRepositoryFileExceptions("Nu s-a putut deschide fisierul pentru scriere");
	}
	out << "<html> <table>";
	for (auto& book : cart) {
		out << "<tr> <td>" << book.getId() << "</td> <td>" << book.getTitle() << "</td> <td>" << book.getAuthor()
			<< "</td> <td>" << book.getSubject() << "</td> <td>" << book.getYear()
			<< "</td></tr>" << std::endl;
	}
	out << "</table> </html>";
	out.close();
}

void CartRepository::exportToCSV() {
	std::ofstream out("export.csv", std::ios::trunc);
	if (!out.is_open()) {
		throw BookstoreRepositoryFileExceptions("Nu s-a putut deschide fisierul pentru scriere");
	}
	for (auto& book : cart) {
		out << book.getId() << ',' << book.getTitle() << ',' << book.getAuthor()
			<< ',' << book.getSubject() << ',' << book.getYear()
			<< std::endl;
	}

	out.close();
}