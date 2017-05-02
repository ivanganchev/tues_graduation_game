#include <SDL.h>
#include <string>
#include <iostream>
#include "GameObject.h"
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

	GameObject::GameObject()
	{

	}

	GameObject::GameObject(const char* image_path, SDL_Surface* screenSurface, SDL_Window* window)
	{
		init(screenSurface, window);
		
		image_path_ = image_path;
		SDL_GetWindowSize(window, &witdhWindow_, &heightWindow_);
		int imgType = IMG_INIT_JPG | IMG_INIT_PNG;
		if (!(IMG_Init(imgType) & imgType))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		}

		image_ = IMG_Load(image_path_);
		if (image_ == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", image_path_, IMG_GetError());
		}


	}


	GameObject::GameObject(SDL_Surface* screenSurface, SDL_Window* window)
	{
		init(screenSurface, window);
	}

	void GameObject::init(SDL_Surface* screenSurface, SDL_Window* window)
	{
		
		isVisible_ = true;
		witdhWindow_ = 0;
		heightWindow_ = 0;
		x_ = 0;
		y_ = 0;
		window_ = window;	
		screenSurface_ = screenSurface;
	}

	void GameObject::show()
	{		

		SDL_Rect srcrect = { x_, y_, 250, 250};
		SDL_Rect dstrect = { x_, y_, 0, 0 };
		SDL_BlitSurface(image_, NULL, screenSurface_, &dstrect);
	}

	void GameObject::set_y(int y)
	{
		y_ = y;
	}

	void GameObject::set_x(int x)
	{
		x_ = x;
	}

	int GameObject::get_x()
	{
		return x_;
	}
	
	 int GameObject::get_y()
	 {
		return y_;
	 }

	 void GameObject::move()
	 {


	 }

	 bool GameObject::isMovable()
	 {
		 return moveFlag_;
	 }

	 bool GameObject::isVisible()
	 {
		 return isVisible_;
	 }

	
	 string GameObject::get_name()
	 {
		 return "";
	 }

	 SDL_Surface* GameObject::get_image()
	 {
		 return image_;
	 }

	 void GameObject::setVisibility(bool visibility)
	 {
		 isVisible_ = visibility;
	 }