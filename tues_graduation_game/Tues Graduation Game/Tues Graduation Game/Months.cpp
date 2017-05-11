#include <SDL_ttf.h>
#include <SDL.h>
#include "Headers/Months.h"
#include "Headers/TextClass.h"
#include "Headers/GameObject.h"

using namespace std;

int month_select = 0;

Months::Months(SDL_Surface *screenSurface, SDL_Window *window) : TextClass(screenSurface, window), months_(vector <string>{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" })
{
	lastTime_ = SDL_GetTicks();
}


void Months::show()
{
	unsigned int seconds, current_time;

	int interval = 10000;
	if (lastTime_ + interval <= SDL_GetTicks()) 
	{
		month_select++;
		lastTime_ = SDL_GetTicks();
	} 

	if (month_select > 11)
	{
		month_select = 0;
	}

	TextClass::set_text(months_[month_select]);
	TextClass::show();
	seconds = 0;
		
	
		

}