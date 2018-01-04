/**
File: Headers\GameObject.h.

Declares the game object class.
**/

#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>


using namespace std;

/**
Author:Ivan Ganchev

Class: GameObject

A game object.
**/
class GameObject {

	/**
	Author:Ivan Ganchev

	Fn: void GameObject::init(SDL_Surface *screenSurface, SDL_Window *window);

	Initializes this object.

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	**/
	void init(SDL_Surface *screenSurface, SDL_Window *window);

protected:

	/** The witdh window. */
	int witdhWindow;

	/** The height window. */
	int heightWindow;

	/** The x coordinate. */
	int x;

	/** The y coordinate. */
	int y;

	/** Full pathname of the image file. */
	const char* image_path;

	/** The screen surface. */
	SDL_Surface* screenSurface;

	/** The image. */
	SDL_Surface* image;

	/** The window. */
	SDL_Window* window;

	/** The image flags. */
	int imgFlags;

	/** The move flag. */
	int moveFlag;

	/** The is visible. */
	int visibility;

	/** The targets. */
	vector<string> targets;

	/** The srcrect. */
	SDL_Rect *srcrect;

	/** The animation. */
	GameObject* animation;

public:

	/**
	Fn: GameObject::GameObject();

	Default constructor.
	**/
	GameObject();

	/**
	Fn: GameObject::GameObject(const char* image_path, SDL_Surface* screenSurface,
	SDL_Window* window);

	Constructor.

	Author:Ivan Ganchev

	Parameters:
	image_path -     Full pathname of the image file.
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	**/
	GameObject(const char* image_path, SDL_Surface* screenSurface, SDL_Window* window);

	/**
	Fn: GameObject::GameObject(SDL_Surface * screenSurface, SDL_Window * window);

	Constructor.

	Author:Ivan Ganchev

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	**/
	GameObject(SDL_Surface * screenSurface, SDL_Window * window);

	/**
	Author:Ivan Ganchev

	Fn: virtual void GameObject::show();

	Shows this object.
	**/
	virtual void show();

	/**
	Author:Ivan Ganchev

	Fn: int GameObject::get_x();

	Get x coordinate.
	Returns: The x coordinate.
	**/
	int get_x();

	/**
	Author:Ivan Ganchev

	Fn: int GameObject::get_y();

	Get y coordinate.
	Returns: The y coordinate.
	**/
	int get_y();

	/** . */
	virtual ~GameObject()
	{}

	/**
	Author:Ivan Ganchev

	Fn: virtual void GameObject::move();

	A virtual method, which is overriden by every class which inherits it.
	**/
	virtual void move();

	/**
	Author:Ivan Ganchev

	Fn: void GameObject::set_y(int y);

	Sets a y coordinate.
	Parameters:
	y -  The y coordinate.
	**/
	void set_y(int y);

	/**
	Author:Ivan Ganchev

	Fn: void GameObject::set_x(int x);

	Sets an x coordinate.
	Parameters:
	x -  The x coordinate.
	**/
	void set_x(int x);

	/**
	Author:Ivan Ganchev

	Fn: bool GameObject::isMovable();

	Method which is used in the main to move the objects in the game.
	Returns: True if movable, false if not.
	**/
	bool isMovable();

	/**
	Author:Ivan Ganchev

	Fn: bool GameObject::isVisible();

	Query if this object is visible.
	Returns: True if visible, false if not and is deleted in the main to free memory and don't slow the process.
	**/
	bool isVisible();

	/**
	Author:Ivan Ganchev

	Fn: virtual string GameObject::get_name();

	Virtual method which is overriden by every object which can be hit and destroyed or is supposed to shoot at something. The name is used to
	Returns: The name.
	**/
	virtual string get_name();

	/**
	Author:Ivan Ganchev

	Fn: SDL_Surface * GameObject::get_image();
	Returns: Null if it fails, else the image.
	**/
	SDL_Surface * get_image();

	/**
	Author:Ivan Ganchev

	Fn: void GameObject::setVisibility(bool visibility);

	Sets a visibility, which is used to know if there was a collision and the object must be deleted to free memory and not slow the process.
	Parameters:
	visibility -  True to visibility.
	**/
	void setVisibility(bool visibility);

	/**
	Author:Ivan Ganchev

	Fn: GameObject GameObject::*getAnimation();

	Gets the animation.
	Returns: Null if it fails, else the animation.
	**/
	GameObject *getAnimation();
};
