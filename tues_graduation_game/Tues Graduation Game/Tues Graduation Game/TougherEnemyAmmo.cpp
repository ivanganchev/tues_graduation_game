#include <SDL.h>
#include <SDL_image.h>
#include "Headers/TougherEnemyAmmo.h"
#include "Headers/GameObject.h"
#include <vector>
#include <string.h>

TougherEnemyAmmo::TougherEnemyAmmo(string name, SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/gotsev.png", screenSurface, window)
{
	targets_ = { "Turret" };
	gameObject_ = gameObject;
	moveFlag_ = true;
	name_ = name;
}

void TougherEnemyAmmo::move()
{
	int h, w;
	if (this->name_ == "middle")
	{
		y_ += 10;
	}
	else if (this->name_ == "right")
	{
		x_ += 7;
		y_ += 7;
	}
	else if (this->name_ == "left")
	{
		x_ -= 7;
		y_ += 7;
	}

	SDL_GetWindowSize(window_, &w, &h);
	if (y_ > h || x_ > w || x_ < 0)
	{
		isVisible_ = false;
	}
}

string TougherEnemyAmmo::get_name()
{
	return "EnemyAmmo";
}
