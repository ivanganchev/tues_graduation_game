#include <SDL.h>
#include <SDL_image.h>
#include "Headers/TougherEnemyAmmo.h"
#include "Headers/GameObject.h"
#include <vector>
#include <string.h>

TougherEnemyAmmo::TougherEnemyAmmo(string name, SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/red laser.png", screenSurface, window)
{
	targets_ = { "Turret" };
	gameObject_ = gameObject;
	moveFlag_ = true;
	name_ = name;
}

void TougherEnemyAmmo::move()
{
	int h, w;
	y_ += 10;
	if (this->get_name() == "middle")
	{
		y_ += 10;
	}
	else if (this->get_name() == "right")
	{
		x_ += 7;
		y_ += 7;
	}
	else if (this->get_name() == "left")
	{
		x_ -= 7;
		y_ += 7;
	}

	SDL_GetWindowSize(window_, &w, &h);
	if (y_ > h)
	{
		isVisible_ = false;
	}
}

string TougherEnemyAmmo::get_name()
{
	return this->name_;
}