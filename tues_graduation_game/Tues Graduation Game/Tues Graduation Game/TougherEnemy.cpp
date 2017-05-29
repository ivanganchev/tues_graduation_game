#include "Headers/TougherEnemy.h"
#include <SDL.h>
#include "Headers/GameObject.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Headers/TougherEnemyAmmo.h"

TougherEnemy::TougherEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObjects) : GameObject("pictures/valkuplane1.png", screenSurface, window)
{
	gameObjects_ = gameObjects;
	moveFlag_ = true;
	srand(time(NULL));
	limit = rand() % 100 + 1;
	speedY = rand() % 10 + 2;
	speedX = rand() % 10 + 2;
	if (speedX % 2 == 0)
	{
		speedX = -speedX;
	}
}

void TougherEnemy::move()
{
	int h, w;

	if (y_ < limit)
	{
		y_ += speedY;
	}
	else
	{
		x_ += speedX;
	}
	if (SDL_GetTicks() % 50 == 0) 
	{
		GameObject* obj = new TougherEnemyAmmo("right", screenSurface_, window_, gameObjects_);
		obj->set_x(x_ + 65);
		obj->set_y(y_ + 109);
		gameObjects_->push_back(obj);
		GameObject *obj1 = new TougherEnemyAmmo("middle", screenSurface_, window_, gameObjects_);
		obj1->set_x(x_ + 65);
		obj1->set_y(y_ + 109);
		gameObjects_->push_back(obj1);
		GameObject *obj2 = new TougherEnemyAmmo("left", screenSurface_, window_, gameObjects_);
		obj2->set_x(x_ + 65);
		obj2->set_y(y_ + 109);
		gameObjects_->push_back(obj2);
	}

	SDL_GetWindowSize(window_, &w, &h);
	if (x_ > w || x_ < -120)
	{
		isVisible_ = false;
	}

}

string TougherEnemy::get_name() 
{
	return "TougherEnemy";
}
