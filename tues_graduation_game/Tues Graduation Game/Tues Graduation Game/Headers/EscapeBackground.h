#pragma once
#include <SDL.h>
#include "GameObject.h"

class EscapeBackground : public GameObject
{
public:
	EscapeBackground(SDL_Surface* screenSurface, SDL_Window* window, const char * imagePath);
	
};

