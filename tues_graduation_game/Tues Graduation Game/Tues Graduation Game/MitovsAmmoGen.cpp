#include <SDL.h>
#include <vector>
#include "MitovsAmmo.h"
#include "MitovsAmmoGen.h"
#include "Generator.h"


MitovsAmmoGen::MitovsAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject)
{

	gameObject_ = gameObject;
}


GameObject* MitovsAmmoGen::create_object()
{
	ammo_ = new MitovsAmmo(screenSurface_, window_, gameObject_);
	return ammo_;

}