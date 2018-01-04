/**
File: Headers\Background.h.

Declares the background class.
**/

#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>

/**
Class: Background

The moving background of the game.

Author: Ivan Ganchev

Date: 11/10/2017
**/

class Background : public GameObject {

public:

	/**
	Fn: Background::Background(SDL_Surface* screenSurface, SDL_Window* window);

	Constructor.

	Author: Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	**/

	Background(SDL_Surface* screenSurface, SDL_Window* window);

	/**
	Fn: void Background::move();

	Moves the background in a vertical way.

	Author: Ivan Ganchev

	Date: 11/10/2017
	**/

	void move();
};
