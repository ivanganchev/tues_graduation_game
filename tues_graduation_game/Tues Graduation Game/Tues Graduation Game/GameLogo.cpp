#include <SDL.h>
#include <iostream>
#include "Headers/GameObject.h"
#include <string>
#include "Headers/GameLogo.h"


GameLogo::GameLogo(SDL_Surface* screenSurface, SDL_Window* window) : GameObject("./pictures/gamelogo.png", screenSurface, window) {

}
