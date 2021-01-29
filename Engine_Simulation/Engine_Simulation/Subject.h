#pragma once
#include"Observer.h"
#include<list>
class Subject
{
public:
	list<Observer*> observers;
	list<Observer*>::iterator it;
	void registerObserver(Observer* observer) {
		observers.push_back(observer);
	}
	void unregisterObserver(Observer* observer) {
		observers.remove(observer);
	}
	void notifyObservers() {
		for (it = observers.begin(); it != observers.end(); ++it) {
			(*it)->update();
		}
	}
};

