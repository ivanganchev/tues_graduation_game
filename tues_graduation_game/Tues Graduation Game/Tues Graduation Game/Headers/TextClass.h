/**
File: Headers\TextClass.h.

Declares the text class class.
**/

#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <iostream>
#include "GameObject.h"

/**
Class: TextClass

A text class.

Author:Ivan Ganchev

Date: 11/10/2017
**/

class TextClass : public GameObject {

	/** The font. */
	TTF_Font *font;

	/** The text. */
	string text;

	/** The text color. */
	SDL_Color textColor = { 255, 255, 255 };

public:

	/**
	Fn: TextClass::TextClass(SDL_Surface* screenSurface, SDL_Window* window);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	**/

	TextClass(SDL_Surface* screenSurface, SDL_Window* window);

	/**
	Fn: void TextClass::show();

	Shows this object.

	Author:Ivan Ganchev

	Date: 11/10/2017
	**/

	void show();

	/**
	Fn: void TextClass::set_text(string text);

	Sets a text.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	text -  The text.
	**/
	void set_text(string text);

	/**
	Fn: TextClass::~TextClass();

	Destructor.

	Author:Ivan Ganchev

	Date: 11/10/2017
	**/
	~TextClass();

};


