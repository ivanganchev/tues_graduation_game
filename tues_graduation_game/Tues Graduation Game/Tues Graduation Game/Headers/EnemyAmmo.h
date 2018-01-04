/**
File: Headers\EnemyAmmo.h.

Declares the enemy ammo class.
**/

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>

/**
Class: EnemyAmmo

An enemy ammo.

Author:Ivan Ganchev

Date: 11/10/2017
**/

class EnemyAmmo : public GameObject {

	/**
	Property: vector <GameObject*> *gameObject_
	**/
	vector <GameObject*> *gameObject;

public:

	/**
	Fn: EnemyAmmo::EnemyAmmo(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/
	EnemyAmmo(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Author:Ivan Ganchev

	Fn: void EnemyAmmo::move();

	Moves this object towards the player.
	**/
	void move();

	/**
	Author:Ivan Ganchev

	Fn: string EnemyAmmo::get_name();

	Gets the name.

	Returns: The name.
	**/
	string get_name();

};
