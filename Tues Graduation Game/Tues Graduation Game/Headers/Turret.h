#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <iostream>
#include <vector>
#include "Ammo.h"
class Turret : public GameObject
{
	
	vector <GameObject*> *gameObjects_;
	Ammo *ammo_ = NULL;
protected:
	SDL_Event keyEvent;
	
public:
	Turret(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	void move();
};