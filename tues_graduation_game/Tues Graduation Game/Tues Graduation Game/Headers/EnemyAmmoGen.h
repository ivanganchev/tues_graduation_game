/**
File: Headers\EnemyAmmoGen.h.

Declares the enemy ammo generate class.
**/

#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"
#include "EnemyAmmo.h"

/**
Class: EnemyAmmoGen

A basic enemy ammo generator.

Author:Ivan Ganchev

**/
class EnemyAmmoGen : public Generator {

	/**
	Author:Ivan Ganchev

	Property: vector <GameObject*> *gameObject_

	Gets the game object.

	Returns: The game object.
	**/
	vector <GameObject*> *gameObject;

	/** The enemy ammo. */
	EnemyAmmo  *enemyAmmo = NULL;

public:

	/**
	Fn: EnemyAmmoGen::EnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/
	EnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Author:Ivan Ganchev

	Fn: GameObject* EnemyAmmoGen::create_object();

	Creates the object, which is the ammo for the basic enemy.

	Returns: Null if it fails, else the new object.
	**/
	GameObject* create_object();
};
