#include <SDL_ttf.h>
#include <SDL.h>
#include "Headers/Months.h"
#include "Headers/TextClass.h"
#include "Headers/GameObject.h"

using namespace std;



Months::Months(SDL_Surface *screenSurface, SDL_Window *window) : TextClass(screenSurface, window), months_(vector <string>{"September", "October", "November", "December","January", "February", "March", "April", "May", "June", "July",})
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

	

	TextClass::set_text(months_[month_select]);
	TextClass::show();
	seconds = 0;
		
	
		

}

string Months::get_name()
{
	return "Months";
}

int Months::month_select = 0;