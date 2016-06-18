#pragma once
#include <qwidget.h>
#include "Observer.h"
#include <qstring.h>
#include "Repository.h"

class ProfesorGUI : public QWidget, public Observer {
private:
	Repository& repo;
	std::string profesor;
	std::vector<float> note;
	QListWidget *list;
	QVBoxLayout *ly;

	void initGUI() {
		repo.addObserver(this);
		ly = new QVBoxLayout();
		this->setWindowTitle((QString::fromStdString(this->profesor)));
		for (auto it = note.begin(); it != note.end(); ++it) {
			auto curent = *it;
			QLabel *lbl = new QLabel();

			lbl->setText(QString::number(curent));
			ly->addWidget(lbl);
		}
		setLayout(ly);
	}

	void clearLy(QLayout *layout) {
		QLayoutItem *item;
		while ((item = layout->takeAt(0))) {
			if (item->widget()) {
				delete item->widget();
			}
			delete item;
		}
	}

	void refresh() {
		this->note = repo.getNote(this->profesor);
		clearLy(ly);

		for (auto it = note.begin(); it != note.end(); ++it) {
			auto curent = *it;
			QLabel *lbl = new QLabel();
			lbl->setText(QString::number(curent));
			ly->addWidget(lbl);
		}
		setLayout(ly);
	}

public:
	ProfesorGUI(Repository& repo, std::string profesor) : repo(repo), profesor(profesor) {
		this->note = repo.getNote(this->profesor);
		initGUI();
	}

	void update() override {

		refresh();
	}

	~ProfesorGUI() {
		repo.removeObserver(this);
	}
};