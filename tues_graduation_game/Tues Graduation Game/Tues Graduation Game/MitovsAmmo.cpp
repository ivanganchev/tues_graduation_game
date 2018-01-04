#include <SDL.h>
#include <SDL_image.h>
#include "Headers/MitovsAmmo.h"
#include "Headers/GameObject.h"
#include <vector>


MitovsAmmo::MitovsAmmo(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/mitovAmmo.png", screenSurface, window) {
	this->targets = { "Turret" };
	this->gameObject = gameObject;
	this->moveFlag = true;
}

void MitovsAmmo::move() {
	int h, w;
	this->y += 10;
	SDL_GetWindowSize(this->window, &w, &h);
	if (this->y > h) {
		this->visibility = false;
	}
}

string MitovsAmmo::get_name() {
	return "MitovsAmmo";
}
