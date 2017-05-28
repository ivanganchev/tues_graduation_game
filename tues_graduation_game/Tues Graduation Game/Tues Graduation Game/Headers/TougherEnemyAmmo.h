
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>


class TougherEnemyAmmo : public GameObject
{
	vector <GameObject*> *gameObject_;
	string name_;

public:
	TougherEnemyAmmo(string name,SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	void move();
	string get_name();
};
