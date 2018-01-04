#include "Headers/TougherEnemy.h"
#include <SDL.h>
#include "Headers/GameObject.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Headers/TougherEnemyAmmo.h"

TougherEnemy::TougherEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObjects) : GameObject("pictures/valkuplane1.png", screenSurface, window) {
	gameObjects_ = gameObjects;
	this->moveFlag = true;
	limit = rand() % 100 + 1;
	speedY = rand() % 10 + 2;
	speedX = rand() % 10 + 2;
	if (speedX % 2 == 0) {
		speedX = -speedX;
	}
}

void TougherEnemy::move() {
	int h, w;

	if (this->y < limit) {
		this->y += speedY;
	} else {
		this->x += speedX;
	}

	if (SDL_GetTicks() % 50 == 0) {
		GameObject* obj = new TougherEnemyAmmo("right", this->screenSurface, this->window, gameObjects_);
		obj->set_x(this->x + 65);
		obj->set_y(this->y + 109);
		gameObjects_->push_back(obj);
		GameObject *obj1 = new TougherEnemyAmmo("middle", this->screenSurface, this->window, gameObjects_);
		obj1->set_x(this->x + 65);
		obj1->set_y(this->y + 109);
		gameObjects_->push_back(obj1);
		GameObject *obj2 = new TougherEnemyAmmo("left", this->screenSurface, this->window, gameObjects_);
		obj2->set_x(this->x + 65);
		obj2->set_y(this->y + 109);
		gameObjects_->push_back(obj2);
	}

	SDL_GetWindowSize(this->window, &w, &h);
	if (this->x > w || this->x < -120) {
		this->visibility = false;
	}

}

string TougherEnemy::get_name() {
	return "TougherEnemy";
}
