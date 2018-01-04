#include <SDL.h>
#include "Headers/GameObject.h"
#include "Headers/Background.h"

Background::Background(SDL_Surface* screenSurface, SDL_Window* window) : GameObject("./pictures/Background.jpg", screenSurface, window) {
	this->moveFlag = true;
}

void Background::move() {
	this->y += 3;
	cout << "TUK SUM" << endl;
	if (this->y >= this->heightWindow) {
		this->y = -this->heightWindow;
	}
}