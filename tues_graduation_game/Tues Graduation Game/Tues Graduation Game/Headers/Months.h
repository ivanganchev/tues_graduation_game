#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "TextClass.h"
#include "GameObject.h"
#include <vector>



class Months : public TextClass
{
	vector<string> months_;
	int lastTime_;
	bool endYear_ = false;
	int accessed;
public:
	static int month_select;
	Months(SDL_Surface *screenSurface, SDL_Window *window);
	void show();
	bool isYearEnded();
	void setYear(bool val);
	string get_name();
};
