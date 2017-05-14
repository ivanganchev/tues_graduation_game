#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"
#include "EnemyAmmo.h"



class EnemyAmmoGen : public Generator
{
	vector <GameObject*> *gameObject_;
	EnemyAmmo  *enemyAmmo_ = NULL;


public:
	EnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	GameObject* create_object();
};




