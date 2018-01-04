#include "Headers/TougherEnemyGen.h"
#include <SDL.h>
#include <vector>
#include "Headers/TougherEnemy.h"

TougherEnemyGen::TougherEnemyGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject) {
	this->gameObject = gameObject;
}

GameObject * TougherEnemyGen::create_object() {
	this->tougherEnemy = new TougherEnemy(this->screenSurface, this->window, this->gameObject);
	int xPos = rand() / 100 * 5;
	int yPos = -rand() % 500 + 1;
	this->tougherEnemy->set_x(xPos);
	this->tougherEnemy->set_y(yPos);

	return this->tougherEnemy;
}
