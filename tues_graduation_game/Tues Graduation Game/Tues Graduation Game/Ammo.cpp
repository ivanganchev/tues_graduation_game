#include <SDL.h>
#include <SDL_image.h>
#include "Headers/Ammo.h"
#include "GameObject.h"
#include <vector>


Ammo::Ammo(SDL_Surface * screenSurface, SDL_Window * window, vector <GameObject*> gameObject): GameObject("pictures/laser.png", screenSurface, window)
{
	gameObjects_ = gameObject;
	targets_ = {"EnemyAmmo", "BasicEnemy"};
	moveFlag_ = true;
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