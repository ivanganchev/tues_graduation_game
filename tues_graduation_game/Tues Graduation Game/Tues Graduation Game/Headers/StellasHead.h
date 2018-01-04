#pragma once
#include <SDL.h>
#include "GameObject.h"

class StellasHead: public GameObject {

protected:
	SDL_Event keyEvent;

public:

	StellasHead(SDL_Surface* screenSurface, SDL_Window* window);

	void move();

	~StellasHead();
};