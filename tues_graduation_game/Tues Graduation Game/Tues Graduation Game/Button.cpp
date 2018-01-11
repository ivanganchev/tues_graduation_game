#include <SDL.h>
#include <SDL_image.h>
#include "Headers/GameObject.h"
#include <vector>
#include "Headers/Button.h"
#include "Headers/Animation.h"
#include "Headers/TextClass.h"

Button::Button(SDL_Surface* screenSurface, SDL_Window* window) : GameObject("pictures/button.png", screenSurface, window) {
	this->buttonText = new TextClass(screenSurface, window);
	clicked = false;
}

void Button::show() {
	SDL_Event event;
	int mouseY;
	int mouseX;



	if(SDL_PollEvent(&event) != 0) {
		if (event.button.button == SDL_BUTTON_LEFT) {
			mouseX = event.button.x;
			mouseY = event.button.y;
			
			if ((mouseX > this->x) && (mouseX < (this->x + this->image->w)) && (mouseY > this->y) && (mouseY < (this->y + this->image->h))) {
					if (event.button.state == SDL_PRESSED) {
						this->image_path = "pictures/clickedButton.png";
						this->image = IMG_Load(this->image_path);
						
					} else if (event.button.state == SDL_RELEASED) {
						this->image_path = "pictures/button.png";
						this->image = IMG_Load(this->image_path);
						this->clicked = true;
						
					}
			}
		}

	}


	int w = 0;
	int	h = 0;
	this->buttonText->setFont("fonts/ka1.ttf", 20);
	this->buttonText->getSize(&w, &h);
	this->buttonText->set_x(this->x + (this->image->w - w)/2);
	this->buttonText->set_y(this->y + (this->image->h - h) / 2 - 3);
	
	GameObject::show();
    this->buttonText->show();
}

void Button::setButtonText(string text) {
	this->buttonText->set_text(text);
}

bool Button::isClicked()
{
	return this->clicked;
}

void Button::clearButtonState() {
	this->clicked = false;
}
 


