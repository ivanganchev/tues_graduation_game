#pragma once
#include "Generator.h"
#include "TougherEnemy.h"
#include <vector>
#include <SDL.h>

class TougherEnemyGen : public Generator
{
	vector <GameObject*> *gameObject_;
	TougherEnemy  *tougherEnemy_ = NULL;
	
public:
		TougherEnemyGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
		GameObject* create_object();
};