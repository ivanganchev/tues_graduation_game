#include <SDL.h>
#include <SDL_image.h>
#include "Headers/GameObject.h"
#include <iostream>
#include "Headers/Turret.h"
#include <vector>
#include "Headers/Turret.h"
#include "Headers/GameEndingScreen.h"
#include "Headers/EventManager.h"

void Turret::moveLeft() {
	if (this->x < 11) {
		this->x -= this->x;
	} else {
		this->x -= 11;
	}
}

void Turret::moveRight() {
	if (this->x >= 1350 - 105) {
		this->x += (1350) - 105 - (this->x);
	} else {
		this->x += 11;
	}
}

void Turret::fire() {
	this->clipSize--;

	if (this->clipSize <= 0) {
		this->timer = SDL_GetTicks();
	}

	this->ammo = new Ammo(this->screenSurface, this->window, *gameObjects);
	this->gameObjects->push_back(this->ammo);
	this->ammo->set_x(this->x + 52 - 10);
	this->ammo->set_y(this->y - 45);
}

Turret::Turret(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/samolet.png", screenSurface, window) {
	this->targets = { "EnemyAmmo", "MitovsAmmo",  "TripleAmmo" };
	this->gameObjects = gameObject;
	this->moveFlag = true;
	this->endFlag = 0;
	this->clipSize = 15;
	this->fireSound = Mix_LoadWAV("music/laser.wav");
}

int Turret::health = 5;


void Turret::move() {
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	SDL_Event keyEventDown = EventManager::keyDown;
	SDL_Event keyEventUp = EventManager::keyUp;


	if (spaceClicked == 1) {
		Mix_PlayChannel(0, fireSound, 1);
		fire();
	} 
	if (leftMove == 1) {
		if (this->x < 11) {
			this->x -= this->x;
		}
		else {
			this->x -= 11;
		}
	}
	if (rightMove == 1) {
		if (this->x >= 1350 - 105) {
			this->x += (1350) - 105 - (this->x);
		}
		else {
			this->x += 11;
		}
	}


	if (this->clipSize <= 0 && (SDL_GetTicks() - this->timer) >= 2000) {
		this->clipSize = 15;
	}

		if (keyEventDown.type == SDL_KEYDOWN) {

			if (keyEventDown.key.keysym.sym == SDLK_SPACE && this->clipSize > 0) {
				spaceClicked = 1;
			}

			if (keyEventDown.key.keysym.sym == SDLK_a) {
				leftMove = 1;
				rightMove = 0;
			}

			if (keyEventDown.key.keysym.sym == SDLK_d) {
				rightMove = 1;
				leftMove = 0;
			}

			EventManager::keyDown = {};

		} else if (keyEventUp.type == SDL_KEYUP) {
			if (keyEventUp.key.keysym.sym == SDLK_SPACE) {
				spaceClicked = 0;
			}

			if (keyEventUp.key.keysym.sym == SDLK_a) {
				leftMove = 0;
			}

			if (keyEventUp.key.keysym.sym == SDLK_d) {
				rightMove = 0;
			}

			EventManager::keyUp = {};

	}
	

	/*if (this->direction == -1) {
		moveLeft();
	}

	if (this->direction == 1) {
		moveRight();
	}*/


	for (int i = 0; i < this->gameObjects->size(); i++) {
		GameObject *obj = (*gameObjects)[i];
		if (get_name() == obj->get_name()) {
			continue;
		}

		if (find(this->targets.begin(), this->targets.end(), obj->get_name()) != this->targets.end()) {
			if (obj->get_x() <= (this->x + this->image->w / 2) &&
				(obj->get_x() + obj->get_image()->w) >= (this->x + this->image->w / 2) &&
				(this->y) <= (obj->get_y() + obj->get_image()->h)) {

				/*if (obj->get_name() != "EnemyAmmo" || obj->get_name() != "MitovsAmmo") {
					if (obj->get_name() == "TripleAmmo") {



						continue;
					}
				}*/

				if (health > 0) {
					health--;
					(*gameObjects)[i]->setVisibility(false);
				} else {

					(*gameObjects)[i]->setVisibility(false);
					setVisibility(false);
					this->endFlag = 1;
					break;
					 
				}

			}
		}
	}

	/*if (this->endFlag == 1) {
		this->end = new GameEndingScreen(this->screenSurface, this->window, this->gameObjects);
		(*gameObjects).push_back(this->end);
	}*/

}





