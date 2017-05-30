#include <SDL.h>
#include <string>
#include <iostream>
#include "Headers/GameObject.h"
#include <SDL_image.h>
#include <vector>
#include "Headers/Background.h"
#include "Headers/MitovsHead.h"
#include "Headers/StellasHead.h"
#include "Headers/TextClass.h"
#include "Headers/Months.h"
#include "Headers/Turret.h"
#include "Headers/BasicEnemy.h"
#include "Headers/Generator.h"
#include "Headers/BasicEnemyGen.h"
#include "Headers/BasicEnemy.h"
#include "Headers/EnemyAmmo.h"
#include "Headers/EnemyAmmoGen.h"
#include "Headers/TougherEnemyGen.h"
#include "Headers/MitovGenerator.h"
#include "Headers/MitovsAmmo.h"
#include "Headers/MitovsAmmoGen.h"
#include "Animation.h"
#include <cstdio>
#include <ctime>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#undef main

using namespace std;

const int SCREEN_WIDTH = 1350;
const int SCREEN_HEIGHT = 695;



int main()
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	bool quit = false;
	SDL_Event e;
	vector <GameObject*> gameObjects;
	const int FRAMES_PER_SECOND = 50;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "Error: " << Mix_GetError() << endl;
	}

	Mix_Music *ebgm = Mix_LoadMUS("music/ebgm.mp3");
	Mix_Music *bgm = Mix_LoadMUS("music/bgm.mp3");
	Mix_PlayMusic(bgm, -1);

	window = SDL_CreateWindow("TUES Graduation Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//window = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	screenSurface = SDL_GetWindowSurface(window);

	Background background1(screenSurface, window);
	background1.set_y(0);

	Background background2(screenSurface, window);
	background2.set_y(-SCREEN_HEIGHT);

	MitovsHead mitovsHead(screenSurface, window, &gameObjects);
	Months months(screenSurface, window);

	Turret spaceship(screenSurface, window, &gameObjects);
	spaceship.set_x(540);
	spaceship.set_y(560);

	GameEndingScreen end(screenSurface, window, &gameObjects);
	BasicEnemyGen enemySpaceshipGen(screenSurface, window, &gameObjects);
	MitovGenerator mitovGen(screenSurface, window, &gameObjects);
	TougherEnemyGen tougherSpaceshipGen(screenSurface, window, &gameObjects);

	gameObjects.push_back(&background1);
	gameObjects.push_back(&background2);
	gameObjects.push_back(&months);
	gameObjects.push_back(&spaceship);


	while (!quit)
	{
		
		
		vector<int> delArray;

		for (int i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i]->isMovable() == true)
			{
				gameObjects[i]->move();
			}



			if (gameObjects[i]->getAnimation() != NULL)
			{
 				gameObjects.push_back(gameObjects[i]->getAnimation());
			}

			
			if (months.isYearEnded())
			{
				while (!Mix_FadeOutMusic(3000) && Mix_PlayingMusic()) {
					SDL_Delay(100);
				}
				months.setYear(false);
				Mix_FreeMusic(bgm);
				Mix_PlayMusic(ebgm, -1);
			}
		

			gameObjects[i]->show();

			if (gameObjects[i]->get_name() != "")
			{
				cout << gameObjects[i]->get_name() << endl;
			}
			if (gameObjects[i]->get_name() == "Months")
			{
				if (Months::month_select < 10)
				{
					enemySpaceshipGen.add(2, 5);
					tougherSpaceshipGen.add(10, 20);
					mitovGen.add(20, 50);
					
				}
				else
				{	
					
					if (find(gameObjects.begin(), gameObjects.end(), &mitovsHead) == gameObjects.end())
					{
   						gameObjects.push_back(&mitovsHead);
					}
					
				}
			}
		}


		while (true)
		{
			int index = -1;
			for (int i = 0; i < gameObjects.size(); i++)
			{
				if (!gameObjects[i]->isVisible())
				{
					index = i;
					break;
				}
			}

			if (index > -1)
			{
				gameObjects.erase(gameObjects.begin() + index);
			}
			else
			{
				break;
			}
			
		}



		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_UpdateWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	
		SDL_Delay(1000 / FRAMES_PER_SECOND);
	}


	return 0;
}