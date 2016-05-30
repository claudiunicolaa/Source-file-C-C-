#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "Book.h"
#include <qdebug.h>

class MyTableModel :public QAbstractTableModel {
private:
	std::vector<Book> books;
public:
	MyTableModel(std::vector<Book> books) : books{ books } {
	}

	void setBooks(std::vector<Book> books) {
		this->books = books;
	}

	int rowCount(const QModelIndex & parent = QModelIndex()) const override {
		return books.size();
	}

	int columnCount(const QModelIndex & parent = QModelIndex()) const override {
		return 4;
	}

	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole) {
			qDebug() << "row:" << index.row() << " col:" << index.column();
			Book b = books[index.row()];
			if (index.column() == 0) {
				return QString::fromStdString(b.getTitle());
			}
			else if (index.column() == 1) {
				return QString::fromStdString(b.getAuthor());
			}
			else if (index.column() == 2) {
				return QString::number(b.getYear());
			}
			else if (index.column() == 3) {
				return QString::fromStdString(b.getSubject());
			}
		}
		return QVariant{};
	}
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
		if (role == Qt::DisplayRole) {
			if (orientation == Qt::Horizontal) {
				switch (section) {
				case 0: return QString("Title");
				case 1: return QString("Author");
				case 2: return QString("Release Year");
				case 3: return QString("Subject");
				default: return QVariant();
				}
			}
			else if (orientation == Qt::Vertical) {
				return section;
			}

		}
		return QVariant();
	}
};