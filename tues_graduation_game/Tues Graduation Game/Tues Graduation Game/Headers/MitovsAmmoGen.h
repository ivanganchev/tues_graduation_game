#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"
#include "MitovsAmmo.h"

/**
Class: MitovsAmmoGen

The boss's ammo generator.

Author:Ivan Ganchev
**/
class MitovsAmmoGen : public Generator {

	/**
	Author:Ivan Ganchev

	Property: vector <GameObject*> *gameObject_

	Gets the game object.

	Returns: The game object.
	**/
	vector <GameObject*> *gameObject;

	/** The ammo object. */
	MitovsAmmo  *ammo = NULL;

public:

	/**
	Fn: MitovsAmmoGen::MitovsAmmoGen(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/
	MitovsAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Author:Ivan Ganchev

	Fn: GameObject* MitovsAmmoGen::create_object();

	Creates the object - the ammo for the boss.

	Returns: Null if it fails, else the new object.
	**/
	GameObject* create_object();
};
