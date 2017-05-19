#include <SDL.h>
#include <vector>
#include "GameObject.h"
#include "MitovGenerator.h"
#include "MitovsHead.h"

MitovGenerator::MitovGenerator(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject)
{
	
	gameObject_ = gameObject;
}


GameObject* MitovGenerator::create_object()
{
	mitov_ = new MitovsHead(screenSurface_, window_);
	int xPos = rand() / 100 * 5;
	int yPos = -rand() % 500 + 1;
	mitov_->set_x(xPos);
	mitov_->set_y(yPos);
	return mitov_;
	
}