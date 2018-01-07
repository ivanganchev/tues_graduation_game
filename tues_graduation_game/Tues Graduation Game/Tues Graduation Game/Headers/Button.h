#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>
#include "Animation.h"
#include "TextClass.h"

class Button : public GameObject {
	vector<GameObject*> gameObjects;
	TextClass *buttonText;
	bool clicked;
public:
	Button(SDL_Surface *screenSurface, SDL_Window *window);
	void show();
	void setButtonText(string text);
	bool isClicked();
	void clearButtonState();
};


