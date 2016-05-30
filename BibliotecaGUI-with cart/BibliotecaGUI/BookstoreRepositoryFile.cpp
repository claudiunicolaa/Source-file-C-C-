#include "BookstoreRepositoryFile.h"


void split(const string& s, const char c, std::vector<string>& v) {
	string::size_type i = 0;
	string::size_type j = s.find(c);

	while (j != string::npos) {
		v.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);
		if (j == string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

void BookstoreRepositoryFile::loadFromFile() {
	string line;
	std::ifstream in(this->fileName);
	if (!in.is_open()) {
		throw BookstoreRepositoryFileExceptions(
			"ERROR: Nu s-a putut deschide fisierul pentru citire("
			+ this->fileName + ")");
	}
	while (std::getline(in, line)) {
		//tokens[0]->id; tokens[1]->title; tokens[2]->author; tokens[3]->subject; tokens[4]->year
		vector<string> tokens;
		split(line, '|', tokens);
		Book book(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3],
			std::stoi(tokens[4]));
		this->addBook(book);
	}

	in.close();
}

void BookstoreRepositoryFile::writeToFile() {
	std::ofstream out(this->fileName);
	if (!out.is_open()) {
		throw BookstoreRepositoryFileExceptions(
			"ERROR: Nu s-a putut deschide fisierul pentru scriere("
			+ this->fileName + ")");
	}
	for (auto& book : getAll()) {
		out << book.getId() << '|' << book.getTitle() << '|' << book.getAuthor()
			<< '|' << book.getSubject() << '|' << book.getYear()
			<< std::endl;
	}
	out.close();
}

