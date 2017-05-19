#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>


class Background: public GameObject
{

public:
	Background(SDL_Surface* screenSurface, SDL_Window* window);
	
	void move();

	
};