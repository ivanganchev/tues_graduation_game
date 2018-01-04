#include <C:\Users\cecoi\Downloads\SDL2-devel-2.0.7-VC\SDL2-2.0.7\include\SDL.h>
#include <SDL_image.h>
#include "Headers/TougherEnemyAmmo.h"
#include "Headers/GameObject.h"
#include <vector>
#include <string.h>

TougherEnemyAmmo::TougherEnemyAmmo(string name, SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/gotsev.png", screenSurface, window) {
	this->targets = { "Turret" };
	this->gameObject = gameObject;
	this->moveFlag = true;
	this->name = name;
}

void TougherEnemyAmmo::move() {
	int h, w;
	if (this->name == "middle") {
		this->y += 10;
	} else if (this->name == "right") {
		this->x += 7;
		this->y += 7;
	} else if (this->name == "left") {
		this->x -= 7;
		this->y += 7;
	}

	SDL_GetWindowSize(this->window, &w, &h);
	if (this->y > h || this->x > w || this->x < 0) {
		this->visibility = false;
	}
}

string TougherEnemyAmmo::get_name() {
	return "EnemyAmmo";
}
