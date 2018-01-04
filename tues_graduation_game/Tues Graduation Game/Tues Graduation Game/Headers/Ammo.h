#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>
#include "Animation.h"
#include <SDL_mixer.h>


/**
Class: Ammo

Player's ammo class

Author: Ivan Ganchev

Date: 11/10/2017
**/
class Ammo : public GameObject {

protected:

	/**
	Author: Ivan Ganchev

	Property: vector <GameObject*> gameObjects_

	Gets the game objects.

	Returns: The game objects.
	**/

	vector <GameObject*> gameObjects;

	/** The explosion. */
	Mix_Chunk *explosion;
	
	/** The hit. */
	Mix_Chunk *mHit;

public:

	/**
	Fn: Ammo::Ammo(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> gameObject);

	Author:Ivan Ganchev

	Constructor.

	Date: 11/9/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	Ammo(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> gameObject);

	/**
	Fn: void Ammo::move();

	Author:Ivan Ganchev

	Moves this object in a certain way.

	Date: 11/9/2017
	**/

	void move();

	/**
	Fn: string Ammo::get_name();

	Author: Ivan Ganchev

	Gets the name.

	Date: 11/9/2017

	Returns: The name, which is used to create the collision and which object is possible to hit.
	**/

	string get_name();

};
