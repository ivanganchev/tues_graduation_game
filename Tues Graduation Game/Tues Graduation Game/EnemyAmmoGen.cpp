#include <SDL.h>
#include <vector>
#include "Headers/EnemyAmmo.h"
#include "Headers/EnemyAmmoGen.h"
#include "Headers/Generator.h"



EnemyAmmoGen::EnemyAmmoGen(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject) : Generator(screenSurface, window, gameObject)
{
	
	gameObject_ = gameObject;
}


GameObject* EnemyAmmoGen::create_object()
{
	enemyAmmo_ = new EnemyAmmo(screenSurface_, window_, gameObject_);
	return enemyAmmo_;

}