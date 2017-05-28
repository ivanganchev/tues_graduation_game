#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Animation.h"

class Animation : public GameObject
{
	int width_;
	int height_;

	private:
		int    CurrentFrame;

		int     FrameInc;

	private:
		int     FrameRate; //Milliseconds

		long    OldTime;

	public:
		int    MaxFrames;

	bool    Oscillate;

	public:
		Animation();
		Animation(SDL_Surface* screenSurface, SDL_Window* window, vector <GameObject*> gameObjects, const char* image_path);

		void OnAnimate();

	public:
		void SetFrameRate(int Rate);

		void SetCurrentFrame(int Frame);

		int GetCurrentFrame();

		void SetFrameSize(int h, int w);

		void show();
};