/**
File: Headers\TougherEnemy.h.

Declares the tougher enemy class.
**/

#pragma once
#include <C:\Users\cecoi\Downloads\SDL2-devel-2.0.7-VC\SDL2-2.0.7\include\SDL.h>
#include "GameObject.h"
#include <vector>
#include "Generator.h"

/**
Class: TougherEnemy

A tougher enemy.

Author:Ivan Ganchev

Date: 11/10/2017
**/

class TougherEnemy : public GameObject {
	/** The limit. */
	int limit;

	/** The speed x coordinate. */
	int speedX;

	/** The speed y coordinate. */
	int speedY;

	/**
	Property: vector <GameObject*> *gameObjects_

	Gets the game objects.

	Returns: The game objects.
	**/

	vector <GameObject*> *gameObjects_;
	/** The last time. */
	int lastTime;

public:

	/**
	Fn: TougherEnemy::TougherEnemy(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	TougherEnemy(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Fn: void TougherEnemy::move();

	Moves this object.

	Author:Ivan Ganchev

	Date: 11/10/2017
	**/

	void move();

	/**
	Fn: string TougherEnemy::get_name();

	Gets the name.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Returns: The name.
	**/

	string get_name();
};
