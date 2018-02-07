#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "GameObject.h"
#include <iostream>
#include <vector>
#include "Ammo.h"
#include "GameEndingScreen.h"

/**
Author:Ivan Ganchev

Class: Turret

Player's vehicle.

Author:Ivan Ganchev
**/
class Turret : public GameObject {

	/**
	Author:Ivan Ganchev

	Property: vector <GameObject*> *gameObjects_

	Gets the game objects.

	Returns: The game objects.
	**/
	vector <GameObject*> *gameObjects;

	/** Player's ammo object. */
	Ammo *ammo = NULL;

	/** Variable which contains . */
	GameEndingScreen *end = NULL;

	/** The end flag. */
	int endFlag;

	/**
	Fn: void Turret::moveLeft();

	Move left.
	**/

	void moveLeft();

	/**
	Fn: void Turret::moveRight();

	Move right.
	**/
	void moveRight();

	/**
	Author:Ivan Ganchev

	Fn: void Turret::fire();

	Method which provides the player with the ability to shoot. Everything happens when the space is clicked - button click recognition.
	**/
	void fire();

	/** The direction. */
	int direction = 0;

	/** Size of the clip. */
	int clipSize;

	/** The timer. */
	int timer = 0;

	/** The fire sound . */
	Mix_Chunk *fireSound;

	int rightMove;
	int leftMove;
	int spaceClicked;

protected:
	


public:

	/**
	Fn: Turret::Turret(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	Turret(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Author:Ivan Ganchev

	Fn: void Turret::move();

	Moves this object with the moveLeft and moveRight methods by button click recognition. Also the collision is put in this method - player's death.
	**/
	void move();

	/** The health. */
	static int health;

	/** True to game over. */
	static bool gameOver;
	
};
