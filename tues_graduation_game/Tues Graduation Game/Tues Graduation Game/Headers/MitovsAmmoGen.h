#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"
#include "MitovsAmmo.h"



class MitovsAmmoGen : public Generator
{
	vector <GameObject*> *gameObject_;
	MitovsAmmo  *ammo_ = NULL;


public:
	MitovsAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	GameObject* create_object();
};
