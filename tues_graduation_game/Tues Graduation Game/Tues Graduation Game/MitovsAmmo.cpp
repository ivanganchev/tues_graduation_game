#include <SDL.h>
#include <SDL_image.h>
#include "Headers/MitovsAmmo.h"
#include "Headers/GameObject.h"
#include <vector>


MitovsAmmo::MitovsAmmo(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/mitovAmmo.png", screenSurface, window)
{
	targets_ = { "Turret" };
	gameObject_ = gameObject;
	moveFlag_ = true;
}

void MitovsAmmo::move()
{
	int h, w;
	y_ += 10;
	SDL_GetWindowSize(window_, &w, &h);
	if (y_ > h)
	{
		isVisible_ = false;
	}
}

string MitovsAmmo::get_name()
{
	return "MitovsAmmo";
}
