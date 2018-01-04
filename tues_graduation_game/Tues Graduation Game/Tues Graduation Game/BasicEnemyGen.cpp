#include <SDL.h>
#include <vector>
#include "Headers/BasicEnemy.h"
#include "Headers/BasicEnemyGen.h"

BasicEnemyGen::BasicEnemyGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject) {
	this->gameObject = gameObject;
}

GameObject* BasicEnemyGen::create_object() {
	basicEnemy = new BasicEnemy(screenSurface, window, gameObject);
	int xPos = rand() / 100 * 5;
	int yPos = -rand() % 500 + 1;
	basicEnemy->set_x(xPos);
	basicEnemy->set_y(yPos);
	return basicEnemy;
}
