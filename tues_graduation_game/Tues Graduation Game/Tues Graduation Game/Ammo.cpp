#include <SDL.h>
#include <SDL_image.h>
#include "Headers/Ammo.h"
#include "GameObject.h"
#include <vector>
#include "Headers/MitovsHead.h"
#include "Headers/Animation.h"

Ammo::Ammo(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> gameObject): GameObject("pictures/laser.png", screenSurface, window)
{
	
	gameObjects_ = gameObject;
	targets_ = { "EnemyAmmo", "BasicEnemy", "Mitov" };
	moveFlag_ = true;
	explosion_ = Mix_LoadWAV("music/explosion.wav");
}

void Ammo::move()
{

	y_-=10;

	if (y_ < -50)
	{
		isVisible_ = false;
	}

	for (int i = 0; i < gameObjects_.size(); i++)
	{
		GameObject *obj = gameObjects_[i];
		if (get_name() == obj->get_name()) {
			continue;
		}

		if (find(targets_.begin(), targets_.end(), obj->get_name()) != targets_.end())
		{
			if (obj->get_x() <= (x_ + image_->w / 2) && (obj->get_x() + obj->get_image()->w) >= (x_ + image_->w / 2) && y_ <= (obj->get_y() + obj->get_image()->h))
			{
				string tempS = obj->get_name();
				if (tempS == "Mitov")
				{
					if (MitovsHead::health > 0)
					{
 						MitovsHead::health--;
						setVisibility(false);
						break;
					}
					else
					{
						gameObjects_[i]->setVisibility(false);
						setVisibility(false);
						break;
					}
				}
				Mix_PlayChannel(0, explosion_, 1);
				
				Animation *exp = new Animation(screenSurface_, window_, gameObjects_, "pictures/explosion.png");
				exp->SetFrameSize(120, 120);
				exp->set_x(gameObjects_[i]->get_x());
				exp->set_y(gameObjects_[i]->get_y());
				animation = exp;
 				gameObjects_[i]->setVisibility(false);
				setVisibility(false); 
				break;
			}
		}
	}
	
}

string Ammo::get_name()
{
	return "playerAmmo";
}
