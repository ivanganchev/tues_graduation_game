#include "Headers/TougherEnemy.h"
#include <SDL.h>
#include "Headers/GameObject.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Headers/EnemyAmmo.h"
#include "Headers/EnemyAmmoGen.h"

TougherEnemy::TougherEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObjects) : GameObject("pictures/valkuplane.png", screenSurface, window)
{
	ammoGen_ = new EnemyAmmoGen(screenSurface, window, gameObjects);
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
/*
bool BasicEnemy::isHit(int xCord, int yCord)
{

if (xCord >= gameObjects_[i] && xCord <= (x_ - 11))

return 1;
}*/

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