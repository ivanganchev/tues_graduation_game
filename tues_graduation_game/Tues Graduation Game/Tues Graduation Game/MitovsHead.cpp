#include <SDL.h>
#include "Headers/MitovsHead.h"
#include "Headers/GameObject.h"
#include "Headers/Months.h"
#include <time.h>
#include "Headers/MitovsAmmo.h"
#include "Headers/Animation.h"

MitovsHead::MitovsHead(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : GameObject("pictures/mitov2.png", screenSurface, window) {
	int h, w;
	SDL_GetWindowSize(this->window, &w, &h);
	this->gen = new MitovsAmmoGen(screenSurface, window, gameObject);
	this->gameObjects = gameObject;
	this->moveFlag = true;
	this->lastTime = SDL_GetTicks();

	if (rand() % 2 == 0) {
		this->direction = 1;
		this->x = 0;
	} else {
		this->direction = -1;
		this->x = w;
	}
}

void MitovsHead::move() {
	int h, w;
	SDL_GetWindowSize(this->window, &w, &h);

	if (Months::month_select < 11) {
		y = 30*sin(x) + 50;
		x += direction * 6;
	} else {
		if (x >= (w-1)-image->w) {
			for (int c = 0; c < 4; c++) {
				a[c] = rand() % 100;
				b[c] = rand() % 100;
			}
			direction = -1;
		} else if(x <= 0) {
			for (int c = 0; c < 4; c++) {
				a[c] = rand() % 100;
				b[c] = rand() % 100;
			}
			direction = 1;
		}
		x += direction * 10;
		y = finalMove(x);
		if (lastTime + 20000 <= SDL_GetTicks()) {
			rain_ammo();
			lastTime = SDL_GetTicks();
		}
	}
	fire();
	beatenMitov();

	if (health == 0) {
		setVisibility(false);
		Animation *exp = new Animation(this->screenSurface, this->window, *this->gameObjects, "pictures/explosion.png");
		exp->SetFrameSize(120, 120);
		exp->set_x(this->x);
		exp->set_y(this->y);
		animation = exp;
	}
}

MitovsHead::~MitovsHead() {
}


string MitovsHead::get_name() {
	return "Mitov";
}

int MitovsHead::health = 100;

int MitovsHead::finalMove(int x) {
	int h, w, i = 0, k = 1;
	SDL_GetWindowSize(this->window, &w, &h);

	if (x > 0 && x <= w * 0.25) {
		i = 0;
		k = 1;
	} else if (x > w * 0.25 && x <= w * 0.50) {
		i = 1;
		k = -1;
	} else if (x > w * 0.50 && x <= w * 0.75) {
		i = 2;
		k = 1;
	} else if (x > w * 0.75 && x <= w) {
		i = 3;
		k = -1;
	}

	return (k*a[i] / 100.0) * x;
}

void MitovsHead::fire() {
	int h, w;
	GameObject *tempPointer = this->gen->get_object();

	this->gen->add(1, 3);
	if (tempPointer != this->gen->get_object()) {
		this->gen->get_object()->set_x(this->x + 65);
		this->gen->get_object()->set_y(this->y + 109);
	}
	SDL_GetWindowSize(this->window, &w, &h);
	if (this->x > w || this->x < -120) {
		this->visibility = false;
	}
}

void MitovsHead::beatenMitov() {
	if (health <= 85 && health > 70) {
		this->image_path = "pictures/beatenMitov1.png";
		this->image = IMG_Load(this->image_path);
	} else if (health <= 70 && health > 50) {
		this->image_path = "pictures/beatenMitov2.png";
		this->image = IMG_Load(this->image_path);
	} else if (health <= 50  && health > 30) {
		this->image_path = "pictures/beatenMitov3.png";
		this->image = IMG_Load(this->image_path);

	}
}


void MitovsHead::rain_ammo() {
	int space = 150;
	int place = 0;

	for (int i = 0; i < 10; i++) {
		this->ammo = new MitovsAmmo(this->screenSurface, this->window, gameObjects);
		this->gameObjects->push_back(this->ammo);
		this->ammo->set_x(place);
		this->ammo->set_y(-50);
		place += space;
	}
}