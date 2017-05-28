#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "MitovsAmmoGen.h"


class MitovsHead : public GameObject
{
	int a[4];
	int b[4];
	int direction_;
	int finalMove(int x);
	MitovsAmmoGen *gen_;
	vector <GameObject*> *gameObjects_;
	int lastTime_;
	MitovsAmmo *ammo_;
	

public:
	static int health;
	MitovsHead(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	void fire();
	void move();
	string get_name();
	void beatenMitov();
	void rain_ammo();
	~MitovsHead();
};