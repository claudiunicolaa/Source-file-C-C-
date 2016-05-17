#include "Book.h"

#include <iostream>

/**
* Default constructor
*/
Book::Book() {
	this->id = -1;
	this->title = "";
	this->author = "";
	this->subject = "";
	this->year = -1;
}

/**
* Constructor with 3 parameters
*/
Book::Book(const int id, const string title, const string author,
	const string subject, const int year) {
	this->id = id;
	this->title = title;
	this->author = author;
	this->subject = subject;
	this->year = year;
}

Book::Book(const Book& other) {
	this->id = other.id;
	this->title = other.title;
	this->author = other.author;
	this->subject = other.subject;
	this->year = other.year;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
	os << book.id << " " << book.title << " " << book.author << " "
		<< book.subject << " " << " " << book.year;
	return os;
}