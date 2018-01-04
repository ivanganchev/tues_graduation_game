#include <SDL.h>
#include <vector>
#include "Headers/GameObject.h"
#include "Headers/MitovGenerator.h"
#include "Headers/MitovsHead.h"

MitovGenerator::MitovGenerator(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject) {

	this->gameObject = gameObject;
}


GameObject* MitovGenerator::create_object() {
	this->mitov = new MitovsHead(this->screenSurface, this->window, this->gameObject);
	int xPos = rand() % 10;
	int yPos = -rand() % 500 + 1;
	/*mitov_->set_x(xPos)*/;
	this->mitov->set_y(yPos);
	return this->mitov;

}