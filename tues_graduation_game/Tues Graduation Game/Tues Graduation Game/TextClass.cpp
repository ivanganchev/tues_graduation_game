#include <SDL_ttf.h>
#include <SDL.h>
#include <iostream>
#include "Headers/GameObject.h"
#include "Headers\TextClass.h"
#include <string>

TextClass::TextClass(SDL_Surface* screenSurface, SDL_Window* window) : GameObject(screenSurface, window) {
	this->moveFlag = true;
}

void TextClass::show() {
	SDL_Surface *ttfText;
	SDL_Color text_color_ = { 255, 255, 255 };

	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	string f_name = "fonts/ka1.ttf";
	this->font = TTF_OpenFont(f_name.c_str(), 24);
	ttfText = TTF_RenderText_Solid(this->font, this->text.c_str(), text_color_);
	SDL_Rect srcrect = { this->x, this->y, 250, 250 };
	SDL_Rect dstrect = { 600, 0, 0, 0 };
	SDL_BlitSurface(ttfText, NULL, this->screenSurface, &dstrect);
}

void TextClass::set_text(string text) {
	this->text = text;
}

TextClass::~TextClass() {

}



