#pragma once
#include <SDL.h>
#include "GameObject.h"


class MitovsHead : public GameObject
{

public:

	MitovsHead(SDL_Surface* screenSurface, SDL_Window* window);
	
	void move();

	~MitovsHead();
};