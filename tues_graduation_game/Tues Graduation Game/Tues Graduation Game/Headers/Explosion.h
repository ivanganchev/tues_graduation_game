/**
File: Headers\Explosion.h.

Declares the explosion class.
**/

#pragma once
#include "GameObject.h"
#include <SDL_Image.h>
#include <SDL.h>

/**
Class: Explosion

An explosion.

Author:Ivan Ganchev

Date: 11/10/2017
**/
class Explosion: public GameObject {
	/** The render target. */
	SDL_Renderer *render_target;

	/** The current image. */
	SDL_Texture *currentImage;

	/** The player rectangle. */
	SDL_Rect playerRect;

public:

	/**
	Fn: Explosion::Explosion(SDL_Surface* screenSurface, SDL_Window* window);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	**/
	Explosion(SDL_Surface* screenSurface, SDL_Window* window);

	/**
	Fn: void Explosion::move();

	Moves this object.

	Author:Ivan Ganchev

	Date: 11/10/2017
	**/
	void move();

};
