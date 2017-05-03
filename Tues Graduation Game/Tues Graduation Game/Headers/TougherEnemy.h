#pragma once
#include <SDL.h>
#include "GameObject.h"
#include <vector>
#include "Generator.h"
#include "EnemyAmmo.h"
#include "EnemyAmmoGen.h"

class TougherEnemy : public GameObject
{
	int limit;
	int speedX;
	int speedY;
	vector <GameObject*> *gameObjects_;
	EnemyAmmoGen *ammoGen_;


public:
	TougherEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	void move();
	//static bool isHit(int xCord, int yCord);
};