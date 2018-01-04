#include <C:\Users\cecoi\Downloads\SDL2-devel-2.0.7-VC\SDL2-2.0.7\include\SDL.h>
#include <vector>
#include "Headers/TougherEnemyAmmo.h"
#include "Headers/TougherEnemyAmmoGen.h"
#include "Headers/Generator.h"

TougherEnemyAmmoGen::TougherEnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject) {

	this->gameObject = gameObject;
}

TougherEnemyAmmoGen::TougherEnemyAmmoGen() {
}

GameObject* TougherEnemyAmmoGen::create_object(string name) {
	this->tougherEnemyAmmo = new TougherEnemyAmmo(name, this->screenSurface, this->window, this->gameObject);
	return this->tougherEnemyAmmo;
}