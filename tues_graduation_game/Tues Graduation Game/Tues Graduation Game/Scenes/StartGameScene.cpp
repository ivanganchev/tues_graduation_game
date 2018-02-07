#include "StartGameScene.h"
#include "../Headers/Scene.h"
#include <SDL.h>
#include <vector>
#include"../Headers/Background.h"
#include "../Headers/Button.h"

StartGameScene::StartGameScene(SDL_Surface *screenSurface, SDL_Window *window, Scene *success) : Scene(screenSurface, window) {
	int width;
	int height;
	
	SDL_GetWindowSize(this->window, &width, &height);
	this->success = success;
	this->failure = failure;
	
	this->startGameButton = new Button(this->screenSurface, this->window);
	this->startGameButton->setButtonText("Start Game");
	this->startGameButton->set_x(300);
	this->startGameButton->set_y(300);

	this->endGameButton = new Button(this->screenSurface, this->window);
	this->endGameButton->setButtonText("End Game");
	this->endGameButton->set_x(300);
	this->endGameButton->set_y(400);

	Background * background1 = new Background(this->screenSurface, this->window);
	background1->set_y(0);



	Background * background2 = new Background(this->screenSurface, this->window);
	background2->set_y(-height);


	gameObjects->push_back(background1);
	gameObjects->push_back(background2);
	gameObjects->push_back(startGameButton);
	gameObjects->push_back(endGameButton);
	

}


bool StartGameScene::quitGame() {
	return this->endGameButton->isClicked();
}

Scene * StartGameScene::getNextScene() {
	if (this->startGameButton->isClicked() == true) {
		this->startGameButton->clearButtonState();
		return this->success;
	}
	return nullptr;
}

