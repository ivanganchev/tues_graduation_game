#pragma once
#include <SDL.h>
#include "GameObject.h"




class TougherEnemyAmmo : public GameObject
{
	
	vector <GameObject*> *gameObject_;
public:
	TougherEnemyAmmo(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	void move();
	string get_name();

};