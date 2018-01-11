#include <SDL.h>
#include <string>
#include <iostream>
#include "Headers/GameObject.h"
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

GameObject::GameObject() {

}

GameObject::GameObject(const char* image_path, SDL_Surface* screenSurface, SDL_Window* window) {
	if (screenSurface == NULL)
		cout << "Error: " << SDL_GetError() << endl;
	init(screenSurface, window);

	this->image_path = image_path;
	SDL_GetWindowSize(window, &witdhWindow, &heightWindow);
	int imgType = IMG_INIT_JPG | IMG_INIT_PNG;
	if (!(IMG_Init(imgType) & imgType)) {
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	image = IMG_Load(this->image_path);

	if (this->image == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", this->image_path, IMG_GetError());
	}
}


GameObject::GameObject(SDL_Surface* screenSurface, SDL_Window* window) {
	init(screenSurface, window);
}

void GameObject::init(SDL_Surface* screenSurface, SDL_Window* window) {

	visibility = true;
	witdhWindow = 0;
	heightWindow = 0;
	x = 0;
	y = 0;
	this->window = window;
	this->screenSurface = screenSurface;
	srcrect = NULL;
	animation = NULL;
}

void GameObject::show() {
	SDL_Rect dstrect = { this->x, this->y, 0, 0 };

	int res = SDL_BlitSurface(this->image, srcrect, this->screenSurface, &dstrect);
	if (res == -1) {
		cout << "Could not get surface: %s\n" << SDL_GetError() << endl;
	}
	
	
}

void GameObject::set_y(int y) {
	this->y = y;
}

void GameObject::set_x(int x) {
	this->x = x;
}

int GameObject::get_x() {
	return this->x;
}

int GameObject::get_y() {
	return this->y;
}

void GameObject::move() {
	

}

bool GameObject::isMovable() {
	return this->moveFlag;
}

bool GameObject::isVisible() {
	return this->visibility;
}


string GameObject::get_name() {
	return "";
}

SDL_Surface* GameObject::get_image() {
	return this->image;
}

void GameObject::setVisibility(bool visibility) {
	this->visibility = visibility;
}

GameObject* GameObject::getAnimation() {
	return animation;
}
