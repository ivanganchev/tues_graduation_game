#include <SDL.h>
#include "GameObject.h"
#include "Background.h"

Background::Background(SDL_Surface* screenSurface, SDL_Window* window) : GameObject("pictures/Background.jpg", screenSurface, window)
{
	
	moveFlag_ = true;
	
}



void Background::move()
{
	
	y_ += 3;
	
	if (y_ >= heightWindow_)
	{
		y_ = -heightWindow_;

	}


}