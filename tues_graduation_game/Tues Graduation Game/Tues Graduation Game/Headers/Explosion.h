#pragma once
#include "GameObject.h"
#include <SDL_Image.h>
#include <SDL.h>


class Explosion: public GameObject 
{
	SDL_Renderer *render_target;
	SDL_Texture *currentImage;
	SDL_Rect playerRect;

	public:
		Explosion(SDL_Surface* screenSurface, SDL_Window* window);

		
			
		void move();

};