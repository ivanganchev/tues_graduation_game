#pragma once
#include <SDL.h>
#include "GameObject.h"
#include <vector>
#include "Generator.h"
#include "EnemyAmmo.h"
#include "EnemyAmmoGen.h"
class BasicEnemy : public GameObject
{
	int limit;
	int speedX;
	int speedY;
	vector <GameObject*> *gameObjects_;
	EnemyAmmoGen *ammoGen_;
	

public:
	BasicEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	void fire();
	void move();
	string get_name();

};