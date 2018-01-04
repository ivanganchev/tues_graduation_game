/**
File: Headers\BasicEnemy.h.

Declares the basic enemy class.
**/

#pragma once
#include <SDL.h>
#include "GameObject.h"
#include <vector>
#include "Generator.h"
#include "EnemyAmmo.h"
#include "EnemyAmmoGen.h"

/**
Class: BasicEnemy

A basic enemy.

Author: Ivan Ganchev

Date: 11/10/2017
**/

class BasicEnemy : public GameObject {

	/** Limit - a variable which is used to limit the plane's forward movement */
	int limit;

	/** The speed x coordinate - randomly generated, which means that everytime the object moves at a different speed */
	int speedX;

	/** The speed y coordinate - randomly generated, which means that everytime the object moves at a different speed. */
	int speedY;

	/**
	Property: vector <GameObject*> *gameObjects_

	Gets the game objects.

	Returns: The game objects.
	**/
	vector <GameObject*> *gameObjects;

	/** The ammo generate. */
	EnemyAmmoGen *ammoGen;

public:

	/**
	Fn: BasicEnemy::BasicEnemy(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author: Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	BasicEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Fn: void BasicEnemy::fire();

	Method which generates bullets for the enemies.

	Author: Ivan Ganchev

	Date: 11/10/2017
	**/

	void fire();

	/**
	Fn: void BasicEnemy::move();

	Moves this object.

	**/

	void move();

	/**
	Fn: string BasicEnemy::get_name();

	Gets the name.

	Author: Ivan Ganchev

	Returns: Returns: The name, which is used to create the collision and which object is possible to hit.
	**/

	string get_name();

};
