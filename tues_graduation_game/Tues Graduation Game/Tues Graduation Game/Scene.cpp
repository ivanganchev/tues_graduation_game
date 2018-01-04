#include "Headers\Scene.h"
#include <SDL_mixer.h>

Scene::Scene(SDL_Surface *screenSurface, SDL_Window *window)
{
	this->screenSurface = screenSurface;
	this->window = window;
	this->gameObjects = new vector<GameObject*>();
	this->musicFileName = nullptr;
}

Scene * Scene::getNextScene()
{
	return nullptr;
}

void Scene::execute()
{	
	for (int i = 0; i < this->gameObjects->size(); i++) {
		if ((*(this->gameObjects))[i]->isMovable() == true) {
			(*this->gameObjects)[i]->move();
		}
		if ((*this->gameObjects)[i]->getAnimation() != NULL) {
			gameObjects->push_back((*this->gameObjects)[i]->getAnimation());
		}

		/*if (this->gameObjects[i]->getAnimation() != NULL) {
			this->gameObjects.push_back(this->gameObjects[i]->getAnimation());
		}*/

	

		(*this->gameObjects)[i]->show();
		this->executeExtension(i);

	}

	

	while (true) {
		int index = -1;
		for (int i = 0; i < gameObjects->size(); i++) {
			if ((*this->gameObjects)[i]->isVisible() == false) {
				index = i;
				break;
			}
		}

		if (index > -1) {
			gameObjects->erase(gameObjects->begin() + index);
		}
		else {
			break;
		}
	}

	this->executeExtension();
}

void Scene::executeExtension() {

}

void Scene::executeExtension(int i) {
}

void Scene::playMusic() {
	if (this->musicFileName != nullptr) {
		Mix_Music *bgm = Mix_LoadMUS(this->musicFileName);
		Mix_PlayMusic(bgm, -1);
	}
}

void Scene::stopMusic() {
}

void Scene::changeMusic() {
}
