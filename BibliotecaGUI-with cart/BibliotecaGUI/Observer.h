#pragma once
#include <vector>
#include <algorithm>

/*
	Abstract class. Update method must be implemented by observers.
*/
class Observer {
public:
	virtual void update() = 0;
};

/*
	Observable or Subject - class that notify changes in it's state
*/
class Observable {
private:
	std::vector<Observer*> observers;
public:
	void addObserver(Observer *observer) {
		observers.push_back(observer);
	}

	void removeObserver(Observer *observer) {
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}

	void notify() {
		for (auto observer : observers) {
			observer->update();
		}
	}
};
