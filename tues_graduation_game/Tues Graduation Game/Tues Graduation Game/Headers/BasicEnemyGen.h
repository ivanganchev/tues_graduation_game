/**
File: Headers\BasicEnemyGen.h.

Declares the basic enemy generate class.
**/

#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"

/**
Class: BasicEnemyGen

Author: Ivan Ganchev

A basic enemy generator.

**/

class BasicEnemyGen : public Generator {

	/**
	Property: vector <GameObject*> *gameObject_

	Gets the game object.

	Returns: The game object.
	**/

	vector <GameObject*> *gameObject;

	/** The newly created object for the basic enemy. */
	BasicEnemy  *basicEnemy = NULL;

public:

	/**
	Fn: BasicEnemyGen::BasicEnemyGen(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	BasicEnemyGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Fn: GameObject* BasicEnemyGen::create_object();

	Author:Ivan Ganchev

	The method used to create object, which is virtual and is overriden.

	Returns: Null if it fails, else the new object.
	**/

	GameObject* create_object();
};
