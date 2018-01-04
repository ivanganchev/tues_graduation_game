
#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Animation.h"

/**
Class: Animation

An animation.

Author: Ivan Ganchev

Date: 11/10/2017
**/

class Animation : public GameObject {

	/** The width. */
	int width;

	/** The height. */
	int height;

private:

	/** The current frame. */
	int    currentFrame;

	/** The frame increment. */
	int     frameInc;

private:

	/** Milliseconds. */
	int     frameRate;

	/** The old time. */
	long    oldTime;

public:

	/** The maximum frames. */
	int    maxFrames;

	/** True to oscillate. */
	bool    oscillate;

public:

	/**
	Fn: Animation::Animation();
	Default constructor.
	**/

	Animation();

	/**
	Fn: Animation::Animation(SDL_Surface* screenSurface, SDL_Window* window,
	vector <GameObject*> gameObjects, const char* image_path);

	Constructor.

	Author: Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	gameObjects -    [in,out] If non-null, the game objects.
	image_path -     Full pathname of the image file.
	**/
	Animation(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> gameObjects, const char* image_path);

	/**
	Fn: void Animation::OnAnimate();

	Executes the animate action.

	Author: Ivan Ganchev

	Date: 11/10/2017
	**/
	void OnAnimate();

public:

	/**
	Fn: void Animation::SetFrameRate(int Rate);

	Sets frame rate.

	Author: Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	Rate -  The rate.
	**/
	void SetFrameRate(int Rate);

	/**
	Fn: void Animation::SetCurrentFrame(int Frame);

	Sets current frame.

	Author: Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	Frame -  The frame.
	**/
	void SetCurrentFrame(int Frame);

	/**
	Fn: int Animation::GetCurrentFrame();

	Gets current frame.

	Author: Ivan Ganchev

	Date: 11/10/2017

	Returns: The current frame.
	**/
	int GetCurrentFrame();

	/**
	Fn: void Animation::SetFrameSize(int h, int w);

	Sets frame size.

	Author: Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	h - 	    The height.
	w - 	    The width.
	**/
	void SetFrameSize(int h, int w);

	/**
	Fn: void Animation::show();

	Shows this object.

	Author: Ivan Ganchev

	Date: 11/10/2017
	**/
	void show();
};
