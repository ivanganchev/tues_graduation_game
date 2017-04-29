#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

class GameObject
{
	void init(SDL_Surface *screenSurface, SDL_Window *window);
protected:
	int witdhWindow_;
	int heightWindow_;
	int x_;
	int y_;
	const char* image_path_;
	SDL_Surface* screenSurface_;
	SDL_Surface* image_;
	SDL_Window* window_;
	int imgFlags_;
	int moveFlag_;
	int isVisible_;
	int isHit_;
	
public:
	GameObject();
	GameObject(const char* image_path, SDL_Surface* screenSurface, SDL_Window* window);
	GameObject(SDL_Surface * screenSurface, SDL_Window * window);
	virtual void show();
	int get_x();
	int get_y();
	virtual ~GameObject()
	{}
	virtual void move();
	virtual bool isHit();
	void set_y(int y);
	void set_x(int x);
	bool isMovable();
	bool isVisible();
	int checkHits();
	
};