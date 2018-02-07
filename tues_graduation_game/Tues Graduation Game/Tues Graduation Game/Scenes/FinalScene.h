#pragma once

#include "../Headers/Scene.h"
#include <SDL.h>
#include <vector>
#include "../Headers/GameEndingScreen.h"

class FinalScene : public Scene{
	GameEndingScreen *finalScene;
public:
	FinalScene(SDL_Surface *screenSurface, SDL_Window *window, const char* image_path);
	
};

