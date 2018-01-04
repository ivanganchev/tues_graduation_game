#include <SDL.h>
#include "Headers/GameObject.h"
#include "Headers/BasicEnemy.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Headers/EnemyAmmo.h"
#include "Headers/Generator.h"
#include "Headers/EnemyAmmoGen.h"

BasicEnemy::BasicEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObjects) : GameObject("pictures/basicenemyplanev1.png", screenSurface, window) {
	this->ammoGen = new EnemyAmmoGen(screenSurface, window, gameObjects);
	this->gameObjects = gameObjects;
	this->moveFlag = true;
	limit = rand() % 100 + 1;
	speedY = rand() % 20 + 2;
	speedX = rand() % 20 + 2;
	if (speedX % 2 == 0) {
		speedX = -speedX;
	}
}

void BasicEnemy::fire() {
	int h, w;
	GameObject *tempPointer = this->ammoGen->get_object();

	this->ammoGen->add(1, 3);
	if (tempPointer != this->ammoGen->get_object()) {
		this->ammoGen->get_object()->set_x(this->x + 65);
		this->ammoGen->get_object()->set_y(this->y + 109);
	}
	SDL_GetWindowSize(this->window, &w, &h);
	if (this->x > w || this->x < -120) {
		this->visibility = false;
	}
}

void BasicEnemy::move() {
	if (this->y < limit) {
		this->y += speedY;
	} else {
		this->x += speedX;
	}

	fire();
}

string BasicEnemy::get_name() {
	return "BasicEnemy";
}