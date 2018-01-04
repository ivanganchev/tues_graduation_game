/**
File: Headers\TougherEnemyGen.h.

Declares the tougher enemy generate class.
**/

#pragma once
#include "Generator.h"
#include "TougherEnemy.h"
#include <vector>
#include <SDL.h>

/**
Class: TougherEnemyGen

A tougher enemy generatator.

Author:Ivan Ganchev
**/

class TougherEnemyGen : public Generator {

	/**
	Property: vector <GameObject*> *gameObject_

	Gets the game object.

	Returns: The game object.
	**/
	vector <GameObject*> *gameObject;

	/** The tougher enemy. */
	TougherEnemy  *tougherEnemy = NULL;

public:

	/**
	Fn: TougherEnemyGen::TougherEnemyGen(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	TougherEnemyGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Author:Ivan Ganchev

	Fn: GameObject* TougherEnemyGen::create_object();

	Creates the object.

	Returns: Null if it fails, else the new object.
	**/

	GameObject* create_object();
};
