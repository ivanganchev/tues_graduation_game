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
#include "../Scenes/LevelOne.h"

class LevelOne : public Scene {
	BasicEnemyGen *enemySpaceshipGen;
	MitovGenerator *mitovGen;
	TougherEnemyGen *tougherSpaceshipGen;
	MitovsHead * mitovsHead;
	Months *months;

public:
	LevelOne(SDL_Surface *screenSurface, SDL_Window *window,  Scene *success, Scene* failure);
protected:
	virtual void executeExtension(int i);

};

