#pragma once
#include <SDL.h>
#include <vector>
#include "GameObject.h"
#include <time.h>



class Generator : public GameObject
{
protected:
	vector <GameObject*> *gameObjects_;
	SDL_Surface* screenSurface_;
	SDL_Window* window_;
	int lastTime_;
	GameObject *lastObj_;

public:
	Generator(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	void add(int fromSec, int toSec);
	
	virtual GameObject* create_object();

	GameObject* get_object();
	
};