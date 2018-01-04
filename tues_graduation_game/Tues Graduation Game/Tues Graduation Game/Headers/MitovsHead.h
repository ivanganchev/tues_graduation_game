#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "MitovsAmmoGen.h"

/**
Class: MitovsHead

The boss itself.

Author:Ivan Ganchev
**/
class MitovsHead : public GameObject {
	/** */
	int a[4];

	/**  */
	int b[4];

	/** The direction in which the boss moves during the normal phase - from left to right or the opposite. */
	int direction;

	/**
	Fn: int MitovsHead::finalMove(int x);

	The movement of the boss when player reaches july - the final fight begins and the boss moves chaocticaly.

	Parameters:
	x -  The x coordinate.

	Returns: An int.
	**/
	int finalMove(int x);

	/** The generate. */
	MitovsAmmoGen *gen;

	/**
	Property: vector <GameObject*> *gameObjects_

	Gets the game objects.

	Returns: The game objects.
	**/
	vector <GameObject*> *gameObjects;

	/** The last time. */
	int lastTime;

	/** The ammo. */
	MitovsAmmo *ammo;

public:

	/** The boss's health. */
	static int health;

	/**
	Fn: MitovsHead::MitovsHead(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/
	MitovsHead(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Fn: void MitovsHead::fire();

	Method which provides the boss with the ability to fire.

	Author:Ivan Ganchev

	Date: 11/10/2017
	**/
	void fire();

	/**
	Author:Ivan Ganchev

	Fn: void MitovsHead::move();

	Moves this object sinusoidal from left to right or the opposite during the normal phase.
	**/
	void move();

	/**
	Author:Ivan Ganchev

	Fn: string MitovsHead::get_name();

	Gets the name.

	Returns: The name.
	**/
	string get_name();

	/**
	Author:Ivan Ganchev

	Fn: void MitovsHead::beatenMitov();

	Method which changes the pictures of the head based on how much damage the player dealt to the boss.


	**/

	void beatenMitov();

	/**
	Author:Ivan Ganchev

	Fn: void MitovsHead::rain_ammo();

	Method which generates a rain made out of ammo.
	**/

	void rain_ammo();

	/**
	Author:Ivan Ganchev

	Fn: MitovsHead::~MitovsHead();

	Destructor.
	**/

	~MitovsHead();
};