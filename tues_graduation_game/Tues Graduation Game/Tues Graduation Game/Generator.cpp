#include "Headers/Generator.h"
#include <SDL.h>
#include <vector>
#include "Headers/GameObject.h"
#include <time.h>


Generator::Generator(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObjects) {

	this->gameObjects = gameObjects;
	this->screenSurface = screenSurface;
	this->window = window;
	this->lastTime = SDL_GetTicks();
}

Generator::Generator() {}

GameObject* Generator::create_object() {
	return NULL;
}

void Generator::add(int fromSec, int toSec) {
	int interval = (fromSec + rand() % (toSec - fromSec + 1)) * 1000;
	if (this->lastTime + interval <= SDL_GetTicks()) {
		GameObject* obj = create_object();
		this->gameObjects->push_back(obj);
		this->lastTime = SDL_GetTicks();
		this->lastObj = obj;
	}
}

GameObject* Generator::get_object() {
	return this->lastObj;
}


