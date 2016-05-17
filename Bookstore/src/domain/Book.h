/*
 * Book.h
 *
 *  Created on: Mar 28, 2016
 *      Author: claudiu
 */

#ifndef DOMAIN_BOOK_H_
#define DOMAIN_BOOK_H_

//#include <iostream>
#include <string>

using namespace std;

class Book {
private:
	int id;
	string title;
	string author;
	string subject;
	int year;
public:

	friend std::ostream& operator<<(std::ostream& os, const Book& book);
	/**
	 * Default constructor
	 */
	Book();

	/**
	 * Constructor with 3 parameters
	 */
	Book(const int, const string, const string, const string, const int);

	Book(const Book& other);

	virtual ~Book() {

	}

	void setAuthor(string author) {
		this->author = author;
	}

	string getAuthor() {
		return author;
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

	string getSubject() const {
		return subject;
	}

	void setSubject(string subject) {
		this->subject = subject;
	}

	string getTitle() const {
		return title;
	}

	void setTitle(string title) {
		this->title = title;
	}

	int getYear() const {
		return year;
	}

	void setYear(int year) {
		this->year = year;
	}

	bool operator==(Book& other) {
		if (this->id != other.id) {
			return false;
		}
		if (this->title != other.title) {
			return false;
		}
		if (this->author != other.author) {
			return false;
		}
		if (this->subject != other.subject) {
			return false;
		}
		if (this->year != other.year) {
			return false;
		}
		return true;
	}

	Book& operator=(const Book& other) {
		if (this != &other) {
			this->id = other.id;
			this->title = other.title;
			this->author = other.author;
			this->subject = other.subject;
			this->year = other.year;
		}
		return *this;
	}

};

#endif /* DOMAIN_BOOK_H_ */
