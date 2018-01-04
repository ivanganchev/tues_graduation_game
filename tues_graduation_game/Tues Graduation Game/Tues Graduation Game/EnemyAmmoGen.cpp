#include <SDL.h>
#include <vector>
#include "Headers/EnemyAmmo.h"
#include "Headers/EnemyAmmoGen.h"
#include "Headers/Generator.h"

EnemyAmmoGen::EnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject) {
	this->gameObject = gameObject;
}

GameObject* EnemyAmmoGen::create_object() {
	enemyAmmo = new EnemyAmmo(screenSurface, window, gameObject);
	return enemyAmmo;
}