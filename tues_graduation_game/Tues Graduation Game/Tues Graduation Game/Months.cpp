#include "Headers/TextClass.h"
#include "Headers/GameObject.h"
#include "Headers/Months.h"

using namespace std;



Months::Months(SDL_Surface *screenSurface, SDL_Window *window) : TextClass(screenSurface, window), months(vector <string> {
	"September", "October", "November", "December","January", "February", "March", "April", "May", "June", "July",
}) {
	this->lastTime = SDL_GetTicks();
	accessed = 0;
}


void Months::show() {

	unsigned int seconds, current_time;
	int interval = 10000;
	if (this->lastTime + interval <= SDL_GetTicks()) {
		month_select++;
		if (month_select == 11 && accessed == 0) {
			this->endYear = true;
			accessed = 1;
		}
		this->lastTime = SDL_GetTicks();
	}

	if (month_select < 11) {
		TextClass::set_text(this->months[month_select]);
		TextClass::show();
	} else {
		setVisibility(false);
	}

	seconds = 0;
}

bool Months::isYearEnded() {
	return this->endYear;
}

void Months::setYear(bool val) {
	this->endYear = val;
}

string Months::get_name() {
	return "Months";
}

int Months::month_select = 0;
