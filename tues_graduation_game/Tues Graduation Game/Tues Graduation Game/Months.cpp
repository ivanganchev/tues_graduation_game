#include <SDL_ttf.h>
#include <SDL.h>
#include "Headers/Months.h"
#include "Headers/TextClass.h"
#include "Headers/GameObject.h"

using namespace std;

int month_select = 0;

Months::Months(SDL_Surface *screenSurface, SDL_Window *window) : TextClass(screenSurface, window), months_(vector <string>{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" })
{
	
}


void Months::show()
{
	unsigned int seconds;

	if (SDL_GetTicks() % 100 == 0) month_select++;
	if (month_select > 11) month_select = 0;

	TextClass::set_text(months_[month_select]);
	TextClass::show();
	seconds = 0;
		
}