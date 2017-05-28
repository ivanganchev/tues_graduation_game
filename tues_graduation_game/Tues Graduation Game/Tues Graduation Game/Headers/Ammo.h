#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>
#include <SDL_mixer.h>


class Ammo : public GameObject
{

protected:
	vector <GameObject*> gameObjects_;
	Mix_Chunk *explosion_;
public:
	Ammo(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> gameObject);
	void move();
	string get_name();

};
