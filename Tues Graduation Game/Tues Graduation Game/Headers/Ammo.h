#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>



class Ammo : public GameObject
{

public:
	Ammo(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	void move();

};