#include <SDL_ttf.h>
#include <SDL.h>
#include <iostream>
#include "Headers/GameObject.h"
#include "Headers/TextClass.h"
#include <string>

TextClass::TextClass(SDL_Surface* screenSurface, SDL_Window* window) : GameObject(screenSurface, window) {
	this->moveFlag = true;
}

void TextClass::show() {
	SDL_Surface *ttfText;

	
	ttfText = TTF_RenderText_Solid(this->font, this->text.c_str(), this->textColor);
	
	SDL_Rect dstrect = { this->x, this->y, 0, 0 };
	SDL_BlitSurface(ttfText, NULL, this->screenSurface, &dstrect);
}

void TextClass::setFont(string font, int size) {
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	this->font = TTF_OpenFont(font.c_str(), size);
}



void TextClass::setColor(Uint8 r, Uint8 g, Uint8 b) {

	this->textColor = {r, g, b};
}


void TextClass::getSize(int *w, int *h) {
	TTF_SizeText(this->font, this->text.c_str(), w, h);
}


void TextClass::set_text(string text ) {
	this->text = text;
}

TextClass::~TextClass() {

}



