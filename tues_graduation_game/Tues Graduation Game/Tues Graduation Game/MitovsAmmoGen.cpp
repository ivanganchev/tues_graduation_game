#include <C:\Users\cecoi\Downloads\SDL2-devel-2.0.7-VC\SDL2-2.0.7\include\SDL.h>
#include <vector>
#include "Headers/MitovsAmmo.h"
#include "Headers/MitovsAmmoGen.h"
#include "Headers/Generator.h"


MitovsAmmoGen::MitovsAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject) {

	this->gameObject = gameObject;
}


GameObject* MitovsAmmoGen::create_object() {
	this->ammo = new MitovsAmmo(this->screenSurface, this->window, this->gameObject);
	return this->ammo;

}