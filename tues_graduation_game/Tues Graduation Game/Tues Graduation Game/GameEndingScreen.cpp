#include <SDL.h>
#include <SDL_image.h>
#include "Headers/GameObject.h"
#include "Headers/GameEndingScreen.h"

GameEndingScreen::GameEndingScreen(SDL_Surface * screenSurface, SDL_Window * window, const char* image_path) : GameObject(image_path, screenSurface, window) {
	this->moveFlag = false;
}