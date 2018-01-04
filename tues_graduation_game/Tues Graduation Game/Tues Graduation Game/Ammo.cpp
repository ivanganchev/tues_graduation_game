#include <SDL.h>
#include <SDL_image.h>
#include "Headers/Ammo.h"
#include "Headers/GameObject.h"
#include <vector>
#include "Headers/MitovsHead.h"
#include "Headers/Animation.h"
//#include "Headers/MitovBeaten.h"
//#include "Headers/MitovBeaten.h"
// 
Ammo::Ammo(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> gameObject) : GameObject("pictures/laserv2.png", screenSurface, window) {

	this->gameObjects = gameObject;
	this->targets = { "EnemyAmmo", "BasicEnemy", "Mitov", "TougherEnemy", "MitovsAmmo" };
	this->moveFlag = true;
	this->explosion = Mix_LoadWAV("music/explosion.wav");
	this->mHit = Mix_LoadWAV("music/mitovhit.wav");
}

void Ammo::move() {
	y -= 10;

	if (y < -50) {
		this->visibility = false;
	}

	for (int i = 0; i < gameObjects.size(); i++) {
		GameObject *obj = gameObjects[i];
		if (get_name() == obj->get_name()) {
			continue;
		}

		if (find(targets.begin(), targets.end(), obj->get_name()) != targets.end()) {
			if (obj->get_x() <= (x + image->w / 2) && 
			   (obj->get_x() + obj->get_image()->w) >= (x + image->w / 2) && 
			   y <= (obj->get_y() + obj->get_image()->h)) {
				string tempS = obj->get_name();
				if (tempS == "Mitov") {
					if (MitovsHead::health > 0) {
						Mix_PlayChannel(0, mHit, 1);
						MitovsHead::health--;
						setVisibility(false);
						break;
					} else {
						this->gameObjects[i]->setVisibility(false);
						setVisibility(false);
						break;
					}
				}
				Mix_PlayChannel(0, explosion, 1);

				Animation *exp = new Animation(screenSurface, window, gameObjects, "pictures/explosion.png");
				exp->SetFrameSize(120, 120);
				exp->set_x(gameObjects[i]->get_x());
				exp->set_y(gameObjects[i]->get_y());
				animation = exp;
				gameObjects[i]->setVisibility(false);
				setVisibility(false);
				break;
			}
		}
	}

}

string Ammo::get_name() {
	return "playerAmmo";
}
