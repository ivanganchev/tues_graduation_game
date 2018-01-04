/**
File: Headers\TougherEnemyAmmo.h.

Declares the tougher enemy ammo class.
**/

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>

/**
Class: TougherEnemyAmmo

A tougher enemy ammo.

Author:Ivan Ganchev

Date: 11/10/2017
**/

class TougherEnemyAmmo : public GameObject {

	/**
	Property: vector <GameObject*> *gameObject_

	Gets the game object.

	Returns: The game object.
	**/

	vector <GameObject*> *gameObject;

	/** The name. */
	string name;

public:

	/**
	Fn: TougherEnemyAmmo::TougherEnemyAmmo(string name,SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	name - 			 The name.
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	TougherEnemyAmmo(string name,SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Fn: void TougherEnemyAmmo::move();

	Moves this object.

	Author:Ivan Ganchev

	Date: 11/10/2017
	**/

	void move();

	/**
	Fn: string TougherEnemyAmmo::get_name();

	Gets the name.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Returns: The name.
	**/

	string get_name();
};
