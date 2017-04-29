#pragma once
#include <SDL.h>
#include "Headers/StellasHead.h"
#include "Headers/GameObject.h"

StellasHead::StellasHead(SDL_Surface* screenSurface, SDL_Window* window) : GameObject("pictures/stelcheto.png", screenSurface, window)
{
	moveFlag_ = true;
}

void StellasHead::move()
{
	if(SDL_PollEvent(&keyEvent))
	{
		if (keyEvent.type == SDL_KEYDOWN) 
		{
			switch (keyEvent.key.keysym.sym)
			{
			case SDLK_w:
				y_-=50;
				break;
			case SDLK_s:
				y_+=50;
				break;
			case SDLK_a:
				x_-=50;
				break;
			case SDLK_d:
				x_+=50;
				break;

			default:
				break;
			}
		}
	}
}





StellasHead::~StellasHead()
{
}

