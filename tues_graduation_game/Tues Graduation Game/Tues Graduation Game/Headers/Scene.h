#pragma once
#include <SDL.h>
#include "GameObject.h"
#include <vector>

class Scene {

protected:
	SDL_Window *window;
	SDL_Surface *screenSurface;
	Scene* success;
	Scene* failure;
	vector<GameObject*> * gameObjects;
	const char *musicFileName;
	const char *bossFightMusic;

public:
	virtual Scene *getNextScene();
	Scene(SDL_Surface *screenSurface, SDL_Window *window);
	void execute();
	virtual void executeExtension();
	virtual void executeExtension(int i);
	void playMusic();
	void stopMusic();
	void changeMusic();
	virtual bool quitGame();
};