#pragma once
#include <qwidget.h>
#include "Observer.h"
#include <qstring.h>
#include "Repository.h"

class ProfesorGUI : public QWidget, public Observer {
private:
	Controller& ctrl;
	std::string profesor;
	std::vector<float> note;
	QListWidget *list;
	QVBoxLayout *ly;

	void initGUI() {
		ctrl.addObserver(this);
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
		this->note = ctrl.getNote(this->profesor);
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
	ProfesorGUI(Controller& ctrl, std::string profesor) : ctrl(ctrl), profesor(profesor) {
		this->note = ctrl.getNote(this->profesor);
		initGUI();
	}

	void update() override {

		refresh();
	}

	~ProfesorGUI() {
		ctrl.removeObserver(this);
	}
};