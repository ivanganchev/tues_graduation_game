#include "Headers/TextClass.h"
#include "Headers/GameObject.h"
#include "Headers/Months.h"

using namespace std;



Months::Months(SDL_Surface *screenSurface, SDL_Window *window) : TextClass(screenSurface, window), months_(vector <string>{"September", "October", "November", "December","January", "February", "March", "April", "May", "June", "July",})
{
	lastTime_ = SDL_GetTicks();
	accessed = 0;
}


void Months::show()
{

	unsigned int seconds, current_time;
	int interval = 10000;
	if (lastTime_ + interval <= SDL_GetTicks())
	{
		month_select++;
		if (month_select == 11 && accessed == 0)
		{
			endYear_ = true;
			accessed = 1;

		}
		lastTime_ = SDL_GetTicks();
	}

	

	
	if (month_select < 11)
	{
		TextClass::set_text(months_[month_select]);
		TextClass::show();
	}
	else
	{
		setVisibility(false);
	}
	
	seconds = 0;




}

bool Months::isYearEnded() 
{
	return endYear_;
}

void Months::setYear(bool val)
{
	endYear_ = val;
}

string Months::get_name()
{
	return "Months";
}

int Months::month_select = 0;
