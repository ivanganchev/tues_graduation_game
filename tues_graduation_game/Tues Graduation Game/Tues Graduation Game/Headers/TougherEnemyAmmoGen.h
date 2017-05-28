#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"
#include "TougherEnemyAmmo.h"

class TougherEnemyAmmoGen : public Generator
{
	vector <GameObject*> *gameObject_;
	TougherEnemyAmmo  *tougherEnemyAmmo_ = NULL;

public:
	TougherEnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	TougherEnemyAmmoGen();
	GameObject* create_object(string name);
};




