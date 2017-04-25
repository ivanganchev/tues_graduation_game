#include <SDL.h>
#include <vector>
#include "BasicEnemy.h"
#include "BasicEnemyGen.h"



BasicEnemyGen::BasicEnemyGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject)
{
	
	gameObject_ = gameObject;
}


GameObject* BasicEnemyGen::create_object()
{
	basicEnemy_ = new BasicEnemy(screenSurface_, window_, gameObject_);
	int xPos = rand() / 100 * 5;
	int yPos = -rand() % 500 + 1;
	basicEnemy_->set_x(xPos);
	basicEnemy_->set_y(yPos);
	return basicEnemy_;
	
}