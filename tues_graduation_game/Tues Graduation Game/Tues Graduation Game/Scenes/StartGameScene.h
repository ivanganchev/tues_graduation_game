#pragma once
#include "../Headers/Scene.h"
#include <SDL.h>
#include <vector>
#include "../Headers/Button.h"
#include "../Headers/GameLogo.h"

class StartGameScene : public Scene {
	Button *startGameButton;
	Button *endGameButton;
	GameLogo *gamelogo;

public:
	StartGameScene(SDL_Surface *screenSurface, SDL_Window *window, Scene *success);

	bool quitGame();
	virtual Scene *getNextScene();
};

