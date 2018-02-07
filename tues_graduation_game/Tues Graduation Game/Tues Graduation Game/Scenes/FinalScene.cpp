#include "FinalScene.h"
#include "../Headers/Scene.h"
#include <SDL.h>
#include <vector>
#include "../Headers/GameEndingScreen.h"

FinalScene::FinalScene(SDL_Surface * screenSurface, SDL_Window * window, const char* image_path) : Scene(screenSurface, window){
		this->finalScene = new GameEndingScreen(screenSurface, window, image_path); 
		gameObjects->push_back(this->finalScene);
};
