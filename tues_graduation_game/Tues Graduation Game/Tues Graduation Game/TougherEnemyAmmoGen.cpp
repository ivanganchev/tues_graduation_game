#include <SDL.h>
#include <vector>
#include "Headers/TougherEnemyAmmo.h"
#include "Headers/TougherEnemyAmmoGen.h"
#include "Headers/Generator.h"

TougherEnemyAmmoGen::TougherEnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject)
{

	gameObject_ = gameObject;
}

TougherEnemyAmmoGen::TougherEnemyAmmoGen()
{
}

GameObject* TougherEnemyAmmoGen::create_object(string name)
{
	tougherEnemyAmmo_ = new TougherEnemyAmmo(name, screenSurface_, window_, gameObject_);
	return tougherEnemyAmmo_;
}