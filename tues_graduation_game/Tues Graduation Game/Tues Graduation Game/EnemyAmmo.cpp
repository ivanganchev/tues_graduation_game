#include <SDL.h>
#include <SDL_image.h>
#include "Headers/EnemyAmmo.h"
#include "Headers/GameObject.h"
#include <vector>


EnemyAmmo::EnemyAmmo(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/red laser.png", screenSurface, window)
{
	gameObject_ = gameObject;
	moveFlag_ = true;
}

void EnemyAmmo::move()
{
	int h, w;
	y_ += 10;
	SDL_GetWindowSize(window_, &w, &h);
	if (y_ > h)
	{
		isVisible_ = false;
	} else if (isHit())
	{

	}
}

