#pragma once
#include <SDL.h>
#include <vector>
#include "GameObject.h"

class GameLogo : public GameObject {
	vector<GameObject*> gameObjects;

	public: 
		GameLogo(SDL_Surface *screenSurface, SDL_Window *window);
};

