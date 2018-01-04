#include "Headers/Animation.h"
#include <SDL.h>

Animation::Animation() {

}

Animation::Animation(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> gameObjects, const char* image_path) : GameObject(image_path, screenSurface, window) {
	currentFrame = 0;
	maxFrames = 0;
	frameInc = 1;

	frameRate = 70;
	oldTime = 0;

	oscillate = false;
	srcrect = new SDL_Rect();
}

void Animation::OnAnimate() {
	if (currentFrame > maxFrames) {
		this->visibility = true;
		return;
	}

	if (oldTime + frameRate > SDL_GetTicks()) {
		return;
	}

	oldTime = SDL_GetTicks();

	currentFrame += frameInc;

	srcrect->x = currentFrame * this->width;
	srcrect->y = 0;
	srcrect->w = this->width;
	srcrect->h = this->height;
}

void Animation::SetFrameRate(int Rate) {
	frameRate = Rate;
}

void Animation::SetCurrentFrame(int frame) {
	if (frame < 0 || frame >= maxFrames) {
		return;
	}

	currentFrame = frame;
}

int Animation::GetCurrentFrame() {
	return currentFrame;
}

void Animation::SetFrameSize(int h, int w) {
	this->height = h;
	this->width = w;
	maxFrames = this->image->w / w;
}

void Animation::show() {
	OnAnimate();
	GameObject::show();
}
