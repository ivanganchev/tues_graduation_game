#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <iostream>
#include "Turret.h"
#include <vector>
#include "Ammo.h"



void Turret::moveLeft()
{
	if (x_ < 11)
	{
		x_ -= x_;
	}
	else
	{
		x_ -= 11;
	}
}

void Turret::moveRight()
{
	if (x_ >= 1350 - 105)
	{
		x_ += (1350) - 105 - (x_);
	}
	else
	{
		x_ += 11;
	}
}

void Turret::fire()
{
	ammo_ = new Ammo(screenSurface_, window_, *gameObjects_);
	gameObjects_->push_back(ammo_);
	ammo_->set_x(x_ + 52 - 10);
	ammo_->set_y(y_ - 45);
}

Turret::Turret(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/samolet.png", screenSurface, window)
{
	gameObjects_ = gameObject;
	moveFlag_ = true;
}


void Turret::move()
{
	
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	unsigned cap = 6;
	if (SDL_PollEvent(&keyEvent))
	{
		
		if (keyEvent.type == SDL_KEYDOWN)
		{
			if (state[SDL_SCANCODE_SPACE]) 
			{
				fire();
			}

			if (state[SDL_SCANCODE_A])
			{
				direction_ = -1;
			}

			if (state[SDL_SCANCODE_D])
			{
				direction_ = 1;
			}
		}
	}

	if (direction_ == -1)
	{
		moveLeft();
	}

	if (direction_ == 1)
	{
		moveRight();
	}
	
}