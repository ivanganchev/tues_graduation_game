#pragma once
#include "../Headers/Scene.h"
#include <SDL.h>
#include <vector>
#include "../Headers/Button.h"

class StartGameScene : public Scene {
	Button *startGameButton;
	Button *endGameButton;

public:
	StartGameScene(SDL_Surface *screenSurface, SDL_Window *window, Scene *success);

	bool quitGame();

};

