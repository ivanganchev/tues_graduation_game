#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>



class MitovsAmmo : public GameObject
{
	vector <GameObject*> *gameObject_;

public:
	MitovsAmmo(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	void move();
	string get_name();
};