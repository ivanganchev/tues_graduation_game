#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"

class BasicEnemyGen : public Generator
{
	vector <GameObject*> *gameObject_;
	BasicEnemy  *basicEnemy_ = NULL;

public:
	BasicEnemyGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	GameObject* create_object();
};



