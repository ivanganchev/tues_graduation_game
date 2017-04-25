#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <iostream>
#include "GameObject.h"

class TextClass : public GameObject
{

	TTF_Font *font_;
	string text_;
	SDL_Color text_color_ = { 255, 255, 255 };

public:
	TextClass(SDL_Surface* screenSurface, SDL_Window* window);
	void show();
	void set_text(string text);
	~TextClass();
	
};


