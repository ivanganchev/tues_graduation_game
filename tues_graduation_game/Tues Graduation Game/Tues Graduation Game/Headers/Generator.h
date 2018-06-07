 #pragma once
#include <SDL.h>
#include <vector>
#include "GameObject.h"
#include <time.h>

/**
Class: Generator

The generator class which purpose is to be inherited and modified for the specific generator we want.

Author:Ivan Ganchev

Date: 11/10/2017
**/
class Generator : public GameObject {
protected:

	/**
	Property: vector <GameObject*> *gameObjects_

	Gets the game objects.

	Returns: The game objects.
	**/
	vector <GameObject*> *gameObjects;

	/** The screen surface. */
	SDL_Surface* screenSurface;

	/** The window. */
	SDL_Window* window;

	/** The last time. */
	int lastTime;

	/** The last object - variable which contains the last object added . */
	GameObject *lastObj;

public:

	/**
	Fn: Generator::Generator(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> *gameObject);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObject -     [in,out] If non-null, the game object.
	**/

	Generator(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);

	/**
	Author:Ivan Ganchev

	Fn: Generator::Generator();

	Default constructor.
	**/

	Generator();

	/**
	Author:Ivan Ganchev

	Fn: void Generator::add(int fromSec, int toSec);

	Method which is used to add objects of the specific generator in GameObjects vector.

	Parameters:
	fromSec -   The minimum time which the object can be generated.
	toSec -     The maximmum time which the object can be generated.
	**/

	void add(int fromSec, int toSec);

	/**
	Author:Ivan Ganchev

	Fn: virtual GameObject* Generator::create_object();

	Virtual method, which is overriden by every class which inherits the Generator class.

	Returns: Null if it fails, else the new object.
	**/

	virtual GameObject* create_object();

	/**
	Author:Ivan Ganchev

	Fn: GameObject* Generator::get_object();

	Gets the object.

	Returns: Null if it fails, else the object.
	**/

	GameObject* get_object();

};