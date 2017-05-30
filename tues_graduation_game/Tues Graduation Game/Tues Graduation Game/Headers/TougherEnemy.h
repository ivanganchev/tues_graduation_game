#pragma once
#include <SDL.h>
#include "GameObject.h"
#include <vector>
#include "Generator.h"

class TougherEnemy : public GameObject
{
	int limit;
	int speedX;
	int speedY;
	vector <GameObject*> *gameObjects_;
	int lastTime_;

public:
	TougherEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	void move();
	string get_name();
};
