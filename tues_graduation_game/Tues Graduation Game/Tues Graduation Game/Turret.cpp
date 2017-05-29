#include <SDL.h>
#include <SDL_image.h>
#include "Headers/GameObject.h"
#include <iostream>
#include "Headers/Turret.h"
#include <vector>
#include "Headers/Turret.h"
#include "Headers/GameEndingScreen.h"

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
	clipSize_--;

	if (clipSize_ <= 0) 
	{
		timer_ = SDL_GetTicks();
	}

	ammo_ = new Ammo(screenSurface_, window_, *gameObjects_);
	gameObjects_->push_back(ammo_);
	ammo_->set_x(x_ + 52 - 10);
	ammo_->set_y(y_ - 45);
}

Turret::Turret(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> *gameObject) : GameObject("pictures/samolet.png", screenSurface, window)
{
	targets_ = { "EnemyAmmo", "MitovsAmmo" };
	gameObjects_ = gameObject;
	moveFlag_ = true;
	endFlag_ = 0;
	clipSize_ = 15;
	fire_ = Mix_LoadWAV("music/laser.wav");
}


void Turret::move()
{

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	unsigned cap = 6;
	if (SDL_PollEvent(&keyEvent))
	{

		if (keyEvent.type == SDL_KEYDOWN)
		{
			if (state[SDL_SCANCODE_SPACE] && clipSize_ > 0)
			{
				Mix_PlayChannel(0, fire_, 1);
				fire();
			}

			if (clipSize_ <= 0 && (SDL_GetTicks() - timer_) >= 2000)
			{
				clipSize_ = 15;
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
		/*if (keyEvent.type == SDL_KEYUP)
		{
		if (!(state[SDL_SCANCODE_D]))
		{
		direction_ = 0;
		}
		}*/
	}

	if (direction_ == -1)
	{
		moveLeft();
	}

	if (direction_ == 1)
	{
		moveRight();
	}


	for (int i = 0; i < gameObjects_->size(); i++)
	{
		GameObject *obj = (*gameObjects_)[i];
		if (get_name() == obj->get_name()) {
			continue;
		}

		if (find(targets_.begin(), targets_.end(), obj->get_name()) != targets_.end())
		{
			if (obj->get_x() <= (x_ + image_->w / 2) && (obj->get_x() + obj->get_image()->w) >= (x_ + image_->w / 2) && (y_ - image_->h) <= (obj->get_y() - obj->get_image()->h))
			{
				(*gameObjects_)[i]->setVisibility(false);
				setVisibility(false);
				endFlag_ = 1;
				break;
			}
		}
	}

	if (endFlag_ == 1)
	{
		end_ = new GameEndingScreen(screenSurface_, window_, gameObjects_);
		//(*gameObjects_).clear();
		(*gameObjects_).push_back(end_);
		//(*gameObjects_)[gameObjects_->size()]->show();


	}

}


