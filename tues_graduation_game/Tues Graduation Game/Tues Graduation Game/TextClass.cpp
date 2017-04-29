#include <SDL_ttf.h>
#include <SDL.h>
#include <iostream>
#include "Headers/GameObject.h"
#include "Headers/TextClass.h"
#include <string>

TextClass::TextClass(SDL_Surface* screenSurface, SDL_Window* window) : GameObject(screenSurface, window)
{
	moveFlag_ = true;
}

void TextClass::show()
{
	SDL_Surface *ttfText;
	SDL_Color text_color_ = { 255, 255, 255 };

	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	string f_name = "fonts/ka1.ttf";
	font_ = TTF_OpenFont(f_name.c_str(), 24);
	ttfText = TTF_RenderText_Solid(font_, text_.c_str(), text_color_);
	SDL_Rect srcrect = { x_, y_, 250, 250 };
	SDL_Rect dstrect = { 600, 0, 0, 0 };
	SDL_BlitSurface(ttfText, NULL, screenSurface_, &dstrect);
}

void TextClass::set_text(string text)
{
	text_ = text;
}

TextClass::~TextClass()
{

}



