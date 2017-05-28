#include <SDL.h>
#include "Headers/GameObject.h"
#include "Headers/BasicEnemy.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Headers/EnemyAmmo.h"
#include "Headers/Generator.h"
#include "Headers/EnemyAmmoGen.h"

BasicEnemy::BasicEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObjects) : GameObject("pictures/basicenemyplanev1.png", screenSurface, window)
{

	ammoGen_ = new EnemyAmmoGen(screenSurface, window, gameObjects);
	gameObjects_ = gameObjects;
	moveFlag_ = true;
	srand(time(NULL));
	limit = rand() % 100 + 1;
	speedY = rand() % 20 + 2;
	speedX = rand() % 20 + 2;
	if (speedX % 2 == 0)
	{
		speedX = -speedX;
	}

}

void BasicEnemy::fire()
{
	int h, w;
	GameObject *tempPointer = ammoGen_->get_object();

	ammoGen_->add(1, 3);
	if (tempPointer != ammoGen_->get_object()) {
		ammoGen_->get_object()->set_x(x_ + 65);
		ammoGen_->get_object()->set_y(y_ + 109);
	}
	SDL_GetWindowSize(window_, &w, &h);
	if (x_ > w || x_ < -120)
	{
		isVisible_ = false;
	}
}


void BasicEnemy::move()
{



	if (y_ < limit)
	{
		y_ += speedY;
	}
	else
	{
		x_ += speedX;
	}

	fire();

}



string BasicEnemy::get_name()
{
	return "BasicEnemy";
}