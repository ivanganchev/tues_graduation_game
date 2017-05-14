#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#pragma once



class GameEndingScreen : public GameObject
{

public:
	GameEndingScreen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);


};