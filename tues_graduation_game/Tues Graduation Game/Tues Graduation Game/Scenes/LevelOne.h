#pragma once
#include "../Headers/Scene.h"
#include <SDL.h>
#include <vector>
#include "../Headers/Background.h"
#include "../Headers/MitovsHead.h"
#include "../Headers/StellasHead.h"
#include "../Headers/TextClass.h"
#include "../Headers/Months.h"
#include "../Headers/Turret.h"
#include "../Headers/BasicEnemy.h"
#include "../Headers/Generator.h"
#include "../Headers/BasicEnemyGen.h"
#include "../Headers/BasicEnemy.h"
#include "../Headers/EnemyAmmo.h"
#include "../Headers/EnemyAmmoGen.h"
#include "../Headers/TougherEnemyGen.h"
#include "../Headers/MitovGenerator.h"
#include "../Headers/MitovsAmmo.h"
#include "../Headers/MitovsAmmoGen.h"
#include "../Headers/Animation.h"
#include "LevelOne.h"
#include "FinalScene.h"

class LevelOne : public Scene {
	BasicEnemyGen *enemySpaceshipGen;
	MitovGenerator *mitovGen;
	TougherEnemyGen *tougherSpaceshipGen;
	MitovsHead * mitovsHead;
	Months *months;
	FinalScene *finalScene;

public:
	LevelOne(SDL_Surface *screenSurface, SDL_Window *window,  Scene *success, Scene* failure);
	virtual Scene *getNextScene();
protected:
	virtual void executeExtension(int i);

};

