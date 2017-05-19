#pragma once
#pragma once
#include <SDL.h>
#include <vector>
#include "Generator.h"
#include "MitovsHead.h"



class MitovGenerator : public Generator
{
	vector <GameObject*> *gameObject_;
	MitovsHead  *mitov_ = NULL;

public:
	MitovGenerator(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> *gameObject);
	GameObject* create_object();
};