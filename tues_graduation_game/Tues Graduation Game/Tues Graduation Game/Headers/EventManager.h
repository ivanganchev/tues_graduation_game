#pragma once
#include <SDL.h>

class EventManager {
public:
	EventManager();
	static SDL_Event keyUp;
	static SDL_Event keyDown;
	static SDL_Event button;
	static SDL_Event quit;
	static SDL_Event escape;
	static SDL_Event lastEvent;
	static void eventListener();
};

