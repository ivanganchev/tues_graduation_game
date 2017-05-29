#include <SDL.h>
#include "Headers/MitovsHead.h"
#include "Headers/GameObject.h"
#include "Months.h"
#include <time.h>
#include "MitovsAmmo.h" 
#include "Animation.h"


MitovsHead::MitovsHead(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : GameObject("pictures/mitov2.png", screenSurface, window)
{
	gen_ = new MitovsAmmoGen(screenSurface, window, gameObject);
	gameObjects_ = gameObject;
	moveFlag_ = true;
	lastTime_ = SDL_GetTicks();
}

void MitovsHead::move()
{
	
	int h, w;
	SDL_GetWindowSize(window_, &w, &h);

	if (Months::month_select < 11)
	{
		
		y_ = 30*sin(x_) + 50;
		x_ += 6;
	}
	else
	{
		if (x_ >= w)
		{
			for (int c = 0; c < 4; c++)
			{
				a[c] = rand() % 100;
				b[c] = rand() % 100;
			}
			direction_ = -1;
		}
		else if(x_ <= 0)
		{
			for (int c = 0; c < 4; c++)
			{
 				a[c] = rand() % 100;
				b[c] = rand() % 100;
			}
  			direction_ = 1;
		}
		x_ += direction_ * 10;
		y_ = finalMove(x_);
		
	}
	fire();
	beatenMitov();
	if (lastTime_ + 20000 <= SDL_GetTicks())
	{
		rain_ammo();
		lastTime_ = SDL_GetTicks();
	}

	if (health == 0)
	{
		setVisibility(false);
		Animation *exp = new Animation(screenSurface_, window_, *gameObjects_, "pictures/explosion.png");
		exp->SetFrameSize(120, 120);
		exp->set_x(x_);
		exp->set_y(y_);
		animation = exp;
	}
}

MitovsHead::~MitovsHead()
{
}


string MitovsHead::get_name()
{
	return "Mitov";
}

int MitovsHead::health = 100;

int MitovsHead::finalMove(int x)
{
	int h, w, y = 0, i = 0, k = 1;
	SDL_GetWindowSize(window_, &w, &h);

	if (x > 0 && x <= w * 0.25)
	{
		i = 0;
		k = 1;
	}
	else if (x > w * 0.25 && x <= w * 0.50)
	{
		i = 1;
		k = -1;
	}
	else if (x > w * 0.50 && x <= w * 0.75)
	{
		i = 2;
		k = 1;
	}
	else if (x > w * 0.75 && x <= w)
	{
		i = 3;
		k = -1;
	}
	double temp;
	
	temp = (k*a[i] / 100.0) * x ;
	
	return temp;
}


void MitovsHead::fire()
{
	int h, w;
	GameObject *tempPointer = gen_->get_object();

	gen_ ->add(1, 3);
	if (tempPointer != gen_->get_object()) {
		gen_->get_object()->set_x(x_ + 65);
		gen_->get_object()->set_y(y_ + 109);
	}
	SDL_GetWindowSize(window_, &w, &h);
	if (x_ > w || x_ < -120)
	{
		isVisible_ = false;
	}
}


void MitovsHead::beatenMitov()
{
	if (health <= 75 && health > 50)
	{
		image_path_ = "pictures/beatenMitov1.png";
		image_ = IMG_Load(image_path_);
	}
	else if (health <= 50 && health > 25)
	{
		image_path_ = "pictures/beatenMitov2.png";
		image_ = IMG_Load(image_path_);
	}
	else if (health <= 25 && health > 0)
	{
		image_path_ = "pictures/beatenMitov3.png";
		image_ = IMG_Load(image_path_);
	}
}


void MitovsHead::rain_ammo()
{
	int space = 150;
	int place = 0;

	for (int i = 0; i < 10; i++)
	{
		ammo_ = new MitovsAmmo(screenSurface_, window_, gameObjects_);
		gameObjects_->push_back(ammo_);
		ammo_->set_x(place);
		ammo_->set_y(-50);
		place += space;
		
	}
}