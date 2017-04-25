#include <SDL.h>
#include <SDL_image.h>
#include "Ammo.h"
#include "GameObject.h"
#include <vector>


Ammo::Ammo(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject): GameObject("pictures/laser.png", screenSurface, window)
{
	moveFlag_ = true;
}

void Ammo::move()
{

	y_-=10;

	if (y_ < -50)
	{
		isVisible_ = false;
	}
}