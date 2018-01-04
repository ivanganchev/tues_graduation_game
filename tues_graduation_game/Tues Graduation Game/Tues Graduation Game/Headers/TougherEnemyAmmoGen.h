/**
File: Headers\TougherEnemyAmmoGen.h.

Declares the tougher enemy ammo generate class.
**/

#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"
#include "TougherEnemyAmmo.h"

/**
Class: TougherEnemyAmmoGen

A tougher enemy ammo generate.

Author:Ivan Ganchev

Date: 11/10/2017
**/
class TougherEnemyAmmoGen : public Generator {

	/**
	Property: vector <GameObject*> *gameObject_

	Gets the game object.

	Returns: The game object.
	**/
	vector <GameObject*> *gameObject;

	/** The tougher enemy ammo. */
	TougherEnemyAmmo  *tougherEnemyAmmo = NULL;

public:

	/**
	Fn: TougherEnemyAmmoGen::TougherEnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	TougherEnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Fn: TougherEnemyAmmoGen::TougherEnemyAmmoGen();

	Default constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017
	**/

	TougherEnemyAmmoGen();

	/**
	Fn: GameObject* TougherEnemyAmmoGen::create_object(string name);

	Creates an object.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	name -  The name.

	Returns: Null if it fails, else the new object.
	**/

	GameObject* create_object(string name);
};
