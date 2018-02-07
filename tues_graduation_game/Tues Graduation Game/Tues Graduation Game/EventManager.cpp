#include "Headers/EventManager.h"
#include <SDL.h>



SDL_Event EventManager::keyUp;
SDL_Event EventManager::keyDown;
SDL_Event EventManager::button;
SDL_Event EventManager::quit;
SDL_Event EventManager::escape;
SDL_Event EventManager::lastEvent;


EventManager::EventManager() {

}

void EventManager::eventListener() {
	SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = event;
			}

			if (event.type == SDL_KEYDOWN) {
				keyDown = event;
			}

			if (event.type == SDL_KEYUP) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					escape = event;
				} else {
					keyUp = event;
				}
			}
			if (event.button.button == SDL_BUTTON_LEFT) {
				button = event;
			}
		
		}
}

