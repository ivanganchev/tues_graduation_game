#include "LevelOne.h"
#include <SDL.h>
#include <vector>
#include "../Headers/Background.h"
#include "../Headers/MitovsHead.h"
#include "../Headers/StellasHead.h"
#include "../Headers/TextClass.h"
#include "../Headers/Months.h"
#include "../Headers/Turret.h"
#include "../Headers/BasicEnemy.h"
#include "../Headers/Generator.h"
#include "../Headers/BasicEnemyGen.h"
#include "../Headers/BasicEnemy.h"
#include "../Headers/EnemyAmmo.h"
#include "../Headers/EnemyAmmoGen.h"
#include "../Headers/TougherEnemyGen.h"
#include "../Headers/MitovGenerator.h"
#include "../Headers/MitovsAmmo.h"
#include "../Headers/MitovsAmmoGen.h"
#include "../Headers/Animation.h"
#include "../Scenes/LevelOne.h"
#include "../Headers/Scene.h"
//#include "../Headers/BonusesGenerator.h"
//#include "../Headers/Bonus.h"

LevelOne::LevelOne(SDL_Surface *screenSurface, SDL_Window *window, Scene *success, Scene* failure) : Scene(screenSurface, window) {

	int width;
	int height;

	SDL_GetWindowSize(this->window, &width, &height);
	this->success = success;
	this->failure = failure;

	Background * background1 = new Background(this->screenSurface, this->window);
	background1->set_y(0);


	Background * background2 = new Background(this->screenSurface, this->window);
	background2->set_y(-height);


	this->mitovsHead = new MitovsHead(this->screenSurface, this->window, gameObjects);
	this->months = new Months(this->screenSurface, this->window);

	Turret * spaceship = new Turret(this->screenSurface, this->window, gameObjects);
	spaceship->set_x(540);
	spaceship->set_y(560);

	this->enemySpaceshipGen = new BasicEnemyGen(this->screenSurface, this->window, gameObjects);
	this->mitovGen = new MitovGenerator(this->screenSurface, this->window, gameObjects);
	this->tougherSpaceshipGen = new TougherEnemyGen(this->screenSurface, this->window, gameObjects);
	//BonusesGenerator bonusesGen(this->screenSurface, this->window, &gameObjects);

	gameObjects->push_back(background1);
	gameObjects->push_back(background2);
	gameObjects->push_back(months);
	gameObjects->push_back(spaceship);

	this->musicFileName = "music/bgm.mp3";

}


void LevelOne::executeExtension(int i)  {

	if ((*this->gameObjects)[i]->get_name() == "Months") {
		if (Months::month_select < 10) {
			enemySpaceshipGen->add(2, 5);
			tougherSpaceshipGen->add(10, 20);
			mitovGen->add(20, 50);
			//bonusesGen.add(40, 90);

		}
		else {
			if (find(this->gameObjects->begin(), this->gameObjects->end(), this->mitovsHead) == this->gameObjects->end()) {
				this->gameObjects->push_back(this->mitovsHead);
			}
		}

		if (this->months->isYearEnded() == true) {
			while (Mix_FadeOutMusic(3000) == false && Mix_PlayingMusic() == true) {
				SDL_Delay(100);
			}
			this->months-> setYear(false);
			this->musicFileName = "music/ebgm.mp3";
			this->playMusic();
		}
	}
}




Scene * LevelOne::getNextScene() {
	if (Turret::health <= 0) {
		return failure;
	} else if (MitovsHead::health <= 0) {
		return success;
	}
	return nullptr;
}