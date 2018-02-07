#include "EscapeScene.h"
#include "StartGameScene.h"
#include "../Headers/Scene.h"
#include <SDL.h>
#include <vector>
#include "../Headers/Background.h"
#include "../Headers/Button.h"
#include "../Headers/EscapeBackground.h"
#include "LevelOne.h"



EscapeScene::EscapeScene(SDL_Surface *screenSurface, SDL_Window *window) : Scene (screenSurface, window) {
	this->escapeB = new EscapeBackground(screenSurface, window, "pictures/EscapeBackground.png");
	this->resumeButton = new Button(this->screenSurface, this->window);
	this->resumeButton->setButtonText("Resume");
	this->resumeButton->set_x(570);
	this->resumeButton->set_y(250);

	this->restartGameButton = new Button(this->screenSurface, this->window);
	this->restartGameButton->setButtonText("Restart");
	this->restartGameButton->set_x(570);
	this->restartGameButton->set_y(350);

	this->endGameButton = new Button(this->screenSurface, this->window);
	this->endGameButton->setButtonText("Exit Game");
	this->endGameButton->set_x(570);
	this->endGameButton->set_y(450);


	gameObjects->push_back(this->escapeB);
	gameObjects->push_back(this->resumeButton);
	gameObjects->push_back(this->restartGameButton);
	gameObjects->push_back(this->endGameButton);
}

bool EscapeScene::quitGame() {
	return this->endGameButton->isClicked();
}

Scene * EscapeScene::getNextScene() {
	if (this->restartGameButton->isClicked() == true) {
		this->restartGameButton->clearButtonState();
		this->restartGameButton->clearButtonState();
		MitovsHead::health = 100;
		Turret::health = 5;
		Months::month_select = 0;
		return new LevelOne(screenSurface, window,
			new FinalScene(screenSurface, window, "pictures/successBackground.png"),
			new FinalScene(screenSurface, window, "pictures/gameendingscreen.png"));
	} else if (this->resumeButton->isClicked() == true) {
		this->resumeButton->clearButtonState();
		return this;
	}
	return nullptr;
}

const char * EscapeScene::getSceneName()
{
	return "EscapeScene";
}




