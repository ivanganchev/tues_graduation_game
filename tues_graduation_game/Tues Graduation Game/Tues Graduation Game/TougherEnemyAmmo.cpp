#include <SDL.h>
#include "TougherEnemyAmmo.h"

TougherEnemyAmmo::TougherEnemyAmmo(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : GameObject("pictures/gotsev.png", screenSurface, window)
{
	moveFlag_ = true;
	targets_ = { "Turret" };
	gameObject_ = gameObject;
}


void TougherEnemyAmmo::move()
{
	int h, w;
	y_ += 10;
	SDL_GetWindowSize(window_, &w, &h);
	if (y_ > h)
	{
		isVisible_ = false;
	}
}

string TougherEnemyAmmo::get_name()
{
	return "TougherEnemyAmmo";
}