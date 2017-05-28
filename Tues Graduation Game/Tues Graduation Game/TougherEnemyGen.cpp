#include "Headers/TougherEnemyGen.h"
#include <SDL.h>
#include <vector>
#include "Headers/TougherEnemy.h"

TougherEnemyGen::TougherEnemyGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject)
{
	gameObject_ = gameObject;
}

GameObject * TougherEnemyGen::create_object()
{
	tougherEnemy_ = new TougherEnemy(screenSurface_, window_, gameObject_);
	int xPos = rand() / 100 * 5;
	int yPos = -rand() % 500 + 1;
	tougherEnemy_->set_x(xPos);
	tougherEnemy_->set_y(yPos);

	return tougherEnemy_;
}
