#pragma once
#include <qpainter.h>
#include <qwidget.h>
#include "Observer.h"
#include "CartRepository.h"

class CartReadOnlyGUI : public QWidget, public Observer {
private:
	CartRepository& cart;
public:
	CartReadOnlyGUI(CartRepository& cart) :cart{ cart } {
		initGUI();

	}

	void initGUI() {
		cart.addObserver(this);

	}

	void paintEvent(QPaintEvent* ev) override {
		QPainter p{ this };
		int count = cart.size();
		while (count != 0) {
			int x = 50 + rand() % (this->width() - 50);
			int y = 50 + rand() % (this->height() - 50);
			p.drawEllipse(QPointF(x, y), 50, 50);
			count--;
		}
	}

	void update() override {
		this->repaint();
	}

	~CartReadOnlyGUI() {
		cart.removeObserver(this);
	}
};