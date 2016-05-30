#pragma once
#include <qwidget.h>
#include "CartRepository.h"
#include "Observer.h"
#include "qtablewidget.h"
#include "qpushbutton.h"
#include "qboxlayout.h"
#include "Book.h"
#include "MyTabelModel.h"

class CartCRUDGUI : public QWidget, public Observer {
private:
	CartRepository& cart;
	QTableView* lst;
	QPushButton* btn;
	QPushButton* btnRandom;
	MyTableModel *myModel;
	QHBoxLayout* ly;

	void refreshTable(const std::vector<Book>& books) {
		this->myModel = new MyTableModel(cart.getAll());
		this->lst->setModel(myModel);
	}

	void initGUI() {
		cart.addObserver(this);
		QHBoxLayout* ly = new QHBoxLayout;
		lst = new QTableView;
		
		
		ly->addWidget(lst);
		btn = new QPushButton("Clear cos");
		ly->addWidget(btn);

		btnRandom = new QPushButton("Add random 4");
		ly->addWidget(btnRandom);
		setLayout(ly);
	}
	void connectSignals() {
		QObject::connect(btn, &QPushButton::clicked, [&]() {
			cart.empty();
		});
		QObject::connect(btnRandom, &QPushButton::clicked, [&]() {
			cart.empty();
			cart.generate(4);
		});
	}
public:
	CartCRUDGUI(CartRepository& cart) :cart{ cart } {
		initGUI();
		connectSignals();
		refreshTable(cart.getAll());
	}

	void update() override {
		refreshTable(cart.getAll());
	}
	~CartCRUDGUI() {
		cart.removeObserver(this);
	}
};