#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>

/**
Class: MitovsAmmo

The boss's ammo.

Author:Ivan Ganchev
**/
class MitovsAmmo : public GameObject {

	/**
	Author:Ivan Ganchev

	Property: vector <GameObject*> *gameObject_

	Gets the game object.

	Returns: The game object.
	**/
	vector <GameObject*> *gameObject;

public:

	/**
	Fn: MitovsAmmo::MitovsAmmo(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/
	MitovsAmmo(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Author:Ivan Ganchev

	Fn: void MitovsAmmo::move();

	Moves this object, towards the player.
	**/
	void move();

	/**
	Author:Ivan Ganchev

	Fn: string MitovsAmmo::get_name();

	Gets the name.

	Returns: The name.
	**/
	string get_name();
};
