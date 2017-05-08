#include <SDL.h>
#include "MitovsHead.h"
#include "GameObject.h"


MitovsHead::MitovsHead(SDL_Surface* screenSurface, SDL_Window* window) : GameObject("pictures/mitov2.png", screenSurface, window)
{
	moveFlag_ = true;
}

void MitovsHead::move()
{
	x_+= 6;
	if (x_ == 1350)
	{
		x_ = -50;
	}

}

MitovsHead::~MitovsHead()
{
}

