#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "TextClass.h"
#include "GameObject.h"
#include <vector>



class Months : public TextClass
{
	vector<string> months_;

public:

	Months(SDL_Surface *screenSurface, SDL_Window *window);
	void show();
};