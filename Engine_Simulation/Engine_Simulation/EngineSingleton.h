#pragma once
#include"Engine.h"
class EngineSingleton
{
private:
	static EngineSingleton* instance;
	Engine *engine;
	EngineSingleton() {
		engine = new Engine();
	};
public:
	static EngineSingleton* getInstance() {

		if (instance == NULL) {
			instance = new EngineSingleton();
		}
		return instance;
	}
	void setEngine(Engine*);
	Engine* getEngine();
};