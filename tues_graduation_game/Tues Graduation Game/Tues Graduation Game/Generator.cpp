#include "Headers/Generator.h"
#include <SDL.h>
#include <vector>
#include "Headers/GameObject.h"
#include <time.h>

Generator::Generator(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObjects)
{

	gameObjects_ = gameObjects;
	screenSurface_ = screenSurface;
	window_ = window;
	lastTime_ = SDL_GetTicks();
}


GameObject* Generator::create_object()
{
	return NULL;
}

void Generator::add(int fromSec, int toSec)
{
	int interval = (fromSec + rand() % (toSec - fromSec + 1)) * 1000;
	if (lastTime_ + interval <= SDL_GetTicks()) {
		GameObject* obj = create_object();
		gameObjects_->push_back(obj);
		lastTime_ = SDL_GetTicks();
		lastObj_ = obj;
	}

}

GameObject* Generator::get_object()
{
	return lastObj_;
}


