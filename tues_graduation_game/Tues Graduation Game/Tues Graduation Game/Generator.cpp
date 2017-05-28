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

Generator::Generator() {}

GameObject* Generator::create_object()
{
	return NULL;
}

void Generator::add(int fromSec, int toSec)
{
	int interval = (fromSec + rand() % (toSec - fromSec + 1)) * 1000;
	if (lastTime_ + interval <= SDL_GetTicks()) 
	{
		GameObject* obj = create_object();
		gameObjects_->push_back(obj);
		lastTime_ = SDL_GetTicks();
		lastObj_ = obj;
	}

}

/*void Generator::tougherAdd(int fromSec, int toSec)
{
	int interval = (fromSec + rand() % (toSec - fromSec + 1)) * 1000;
	if (lastTime_ + interval <= SDL_GetTicks())
	{
		TougherEnemyAmmoGen gen;
		GameObject* obj = gen.create_object("right");
		gameObjects_->push_back(obj);
		obj = gen.create_object("middle");
		gameObjects_->push_back(obj);
		obj = gen.create_object("left");
		gameObjects_->push_back(obj);
		lastTime_ = SDL_GetTicks();
		lastObj_ = obj;
	}

}*/

GameObject* Generator::get_object()
{
	return lastObj_;
}


