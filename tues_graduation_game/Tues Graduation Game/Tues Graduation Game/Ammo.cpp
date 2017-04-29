#include <SDL.h>
#include <SDL_image.h>
#include "Headers/Ammo.h"
#include "Headers/GameObject.h"
#include <vector>
#include "Headers/BasicEnemy.h""

Ammo::Ammo(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject): GameObject("pictures/laser.png", screenSurface, window)
{
	moveFlag_ = true;
}

void Ammo::move()
{

	y_ -= 10;

	if (y_ < -50)
	{
		isVisible_ = false;
	} else 
	if(BasicEnemy::isHit(x_, y_))
	{
		isHit_ = 1;
	}

}