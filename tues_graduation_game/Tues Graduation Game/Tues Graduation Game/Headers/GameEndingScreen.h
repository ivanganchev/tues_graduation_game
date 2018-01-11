

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"

/**
Class: GameEndingScreen

A game ending screen.

Author:Ivan Ganchev
**/

class GameEndingScreen : public GameObject {




public:

	/**
	Fn: GameEndingScreen::GameEndingScreen(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	GameEndingScreen(SDL_Surface* screenSurface, SDL_Window* window, const char* image_path);

};
