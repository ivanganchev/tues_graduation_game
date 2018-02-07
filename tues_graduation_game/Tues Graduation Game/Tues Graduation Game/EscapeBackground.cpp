#include "Headers/EscapeBackground.h"
#include <SDL.h>
#include "Headers/GameObject.h"



EscapeBackground::EscapeBackground(SDL_Surface* screenSurface, SDL_Window* window, const char * imagePath) : GameObject(imagePath, screenSurface, window) {

}


