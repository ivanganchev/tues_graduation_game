﻿#include <SDL.h>
#include <string>
#include <iostream>
#include "Headers/GameObject.h"
#include <SDL_image.h>
#include <vector>
#include "Headers/Background.h"
#include "Headers/MitovsHead.h"
#include "Headers/StellasHead.h"
#include "Headers/TextClass.h"
#include "Headers/Months.h"
#include "Headers/Turret.h"
#include "Headers/BasicEnemy.h"
#include "Headers/Generator.h"
#include "Headers/BasicEnemyGen.h"
#include "Headers/BasicEnemy.h"
#include "Headers/EnemyAmmo.h"
#include "Headers/EnemyAmmoGen.h"
#include "Headers/TougherEnemyGen.h"
#include "Headers/MitovGenerator.h"
#include "Headers/MitovsAmmo.h"
#include "Headers/MitovsAmmoGen.h"
#include "Headers/Animation.h"
#include "Scenes/LevelOne.h"
#include "Headers/Scene.h"
#include "Scenes/StartGameScene.h"
#include "Scenes/EscapeScene.h"
#include "Headers/EventManager.h"
//#include "Headers/BonusesGenerator.h"
//#include "Headers/Bonus.h"
#include <cstdio>
#include <ctime>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#undef main

using namespace std;

const int SCREEN_WIDTH = 1350;
const int SCREEN_HEIGHT = 695;
const int FRAMES_PER_SECOND = 50;

int main() {

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		cout << "Error: " << Mix_GetError() << endl;
	}

	SDL_Window* window = SDL_CreateWindow("TUES Graduation Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		// In the case that the window could not be made...
		cout << "Error: " << SDL_GetError() << endl;
		return 1;
	}

	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	if (screenSurface == NULL) {
		// In the case that the window could not be made...
		cout << "Error: " << SDL_GetError() << endl;
		return 1;
	}
 
	Scene * currentScene = new StartGameScene(screenSurface, window, 
		new LevelOne(screenSurface, window, 
			new FinalScene(screenSurface, window, "pictures/successBackground.png"), 
			new FinalScene(screenSurface, window, "pictures/gameendingscreen.png")));
	bool escapeClicked = false;
	Scene *temporarySceneContainer = NULL;
	Scene *previousSceneContainer = NULL;
	//currentScene->playMusic();
 
	bool quit = false;
	while (quit == false) {
		currentScene->execute();
		quit = currentScene->quitGame();

		EventManager::eventListener();

		if(EventManager::quit.type != 0) {
			quit = true;
		} else if (EventManager::escape.type != 0) {
			if (escapeClicked == false) {
				temporarySceneContainer = currentScene;
				currentScene = new EscapeScene(screenSurface, window);
				escapeClicked = true;
			} else {
				currentScene = temporarySceneContainer;
				escapeClicked = false;
			}
			EventManager::escape = {};
		}

		Scene *nextScene = currentScene->getNextScene();
		if (nextScene == currentScene) {
			currentScene = temporarySceneContainer;
		} else if (nextScene != NULL) {
			escapeClicked = false;
			currentScene = nextScene;
		} 

		

		SDL_UpdateWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
		SDL_Delay(1000/FRAMES_PER_SECOND);
	}

	return 0;
}
  