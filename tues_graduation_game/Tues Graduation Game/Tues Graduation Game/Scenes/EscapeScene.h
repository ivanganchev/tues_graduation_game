#pragma once
#include "StartGameScene.h"
#include "../Headers/Scene.h"
#include <SDL.h>
#include <vector>
#include"../Headers/Background.h"
#include "../Headers/Button.h"
#include "../Headers/EscapeBackground.h"
#include "../Headers/Button.h"

class EscapeScene : public Scene {
	Button *restartGameButton;
	Button *resumeButton;
	Button *endGameButton;
	
	
public:
	EscapeScene(SDL_Surface *screenSurface, SDL_Window *window);
	EscapeBackground * escapeB;
	bool quitGame();
	Scene *getNextScene();
	virtual const char * getSceneName();
	
};

