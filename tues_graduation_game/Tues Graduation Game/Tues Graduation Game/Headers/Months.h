#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "TextClass.h"
#include "GameObject.h"
#include <vector>

/**
Class: Months

A months.

Author:Ivan Ganchev

Date: 11/10/2017
**/

class Months : public TextClass {
	/** The months. */
	vector<string> months;

	/** The last time. */
	int lastTime;

	/** True to end year. */
	bool endYear = false;

	/** The accessed. */
	int accessed;

public:

	/** The month select. */
	static int month_select;

	/**
	Fn: Months::Months(SDL_Surface *screenSurface, SDL_Window *window);

	Constructor.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	screenSurface -  [in,out] If non-null, the screen surface.
	window - 		 [in,out] If non-null, the window.
	**/
	Months(SDL_Surface *screenSurface, SDL_Window *window);

	/**
	Fn: void Months::show();

	Shows this object.

	Author:Ivan Ganchev

	Date: 11/10/2017
	**/
	void show();

	/**
	Fn: bool Months::isYearEnded();

	Query if this object is year ended.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Returns: True if year ended, false if not.
	**/

	bool isYearEnded();

	/**
	Fn: void Months::setYear(bool val);

	Sets a year.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Parameters:
	val -  True to value.
	**/

	void setYear(bool val);

	/**
	Fn: string Months::get_name();

	Gets the name.

	Author:Ivan Ganchev

	Date: 11/10/2017

	Returns: The name.
	**/

	string get_name();
};
