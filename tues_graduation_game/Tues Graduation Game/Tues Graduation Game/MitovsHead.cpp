#include <SDL.h>
#include "MitovsHead.h"
#include "GameObject.h"


MitovsHead::MitovsHead(SDL_Surface* screenSurface, SDL_Window* window) : GameObject("pictures/mitov2.png", screenSurface, window)
{
	moveFlag_ = true;
}

void MitovsHead::move()
{
	y_ = 30*sin(x_) + 50;
	x_ += 6;

}

MitovsHead::~MitovsHead()
{
}

