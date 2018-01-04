#include <SDL.h>
#include <SDL_image.h>
#include "Headers/EnemyAmmo.h"
#include "Headers/GameObject.h"
#include <vector>


EnemyAmmo::EnemyAmmo(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/gotsev.png", screenSurface, window) {
	this->targets = { "Turret" };
	this->gameObject = gameObject;
	this->moveFlag = true;
}

void EnemyAmmo::move() {
	int h, w;
	this->y += 10;
	SDL_GetWindowSize(this->window, &w, &h);
	if (this->y > h) {
		this->visibility = false;
	}
}

string EnemyAmmo::get_name() {
	return "EnemyAmmo";
}