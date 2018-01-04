#pragma once
#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"
#include "MitovsHead.h"

/**
Class: MitovGenerator

A mitov generator - the boss.

Author:Ivan Ganchev
**/

class MitovGenerator : public Generator {
	/**
	Author:Ivan Ganchev

	Property: vector <GameObject*> *gameObject_

	Gets the game object.

	Returns: The game object.
	**/
	vector <GameObject*> *gameObject;

	/** Variable which contains the Boss. */
	MitovsHead  *mitov = NULL;

public:

	/**
	Fn: MitovGenerator::MitovGenerator(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/
	MitovGenerator(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Author:Ivan Ganchev

	Fn: GameObject* MitovGenerator::create_object();

	Creates the object.

	Returns: Null if it fails, else the new object.
	**/
	GameObject* create_object();
};
