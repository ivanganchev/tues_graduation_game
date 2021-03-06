 #pragma once
#include "Headers/Explosion.h"
#include "Headers/GameObject.h"
#include <SDL.h>

Explosion::Explosion(SDL_Surface* screenSurface, SDL_Window* window) : GameObject("pictures/explosion.png", screenSurface, window) {
	this->moveFlag = true;
	this->render_target = nullptr;
	this->currentImage = nullptr;

	this->render_target = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//this->currentImage = LoadTexture("pictures/explosive.png", render_target);
}

void Explosion::move() {

}