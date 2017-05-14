#include <SDL.h>
#include <SDL_image.h>
#include "Headers/GameObject.h"
#include "Headers/GameEndingScreen.h"

GameEndingScreen::GameEndingScreen(SDL_Surface * screenSurface, SDL_Window * window, vector<GameObject*>* gameObject) : GameObject("pictures/gameendingscreen.png", screenSurface, window)
{
	moveFlag_ = false;
}