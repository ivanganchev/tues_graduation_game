#include "Animation.h"
#include <SDL.h>

Animation::Animation()
{

}
Animation::Animation(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> gameObjects, const char* image_path) : GameObject(image_path, screenSurface, window)
{
	CurrentFrame = 0;
	MaxFrames = 0;
	FrameInc = 1;

	FrameRate = 70; 
	OldTime = 0;

	Oscillate = false;
	srcrect = new SDL_Rect();
}

void Animation::OnAnimate() {
	if (CurrentFrame > MaxFrames) {
		isVisible_ = true;
		return;
	}

	if (OldTime + FrameRate > SDL_GetTicks()) {
		return;
	}

	OldTime = SDL_GetTicks();

	CurrentFrame += FrameInc;

	srcrect->x = CurrentFrame * width_;
	srcrect->y = 0;
	srcrect->w = width_;
	srcrect->h = height_;
	

}

void Animation::SetFrameRate(int Rate) {
	FrameRate = Rate;
}

void Animation::SetCurrentFrame(int Frame) {
	if (Frame < 0 || Frame >= MaxFrames) return;

	CurrentFrame = Frame;
}

int Animation::GetCurrentFrame() {
	return CurrentFrame;
}
void Animation::SetFrameSize(int h, int w)
{
	height_ = h;
	width_ = w;
	MaxFrames = image_->w / w;
}
void Animation::show()
{
	OnAnimate();
	GameObject::show();
}