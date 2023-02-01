#include"libOne.h"
#include"GAME.h"
#include "STAGE_LIVING.h"
STAGE_LIVING::STAGE_LIVING(class GAME* game) :
	SCENE(game) {

}

STAGE_LIVING::~STAGE_LIVING() {
}

void STAGE_LIVING::draw() {
	clear();
	printSize(50);
	print("STAGE_LIVING");
}

void STAGE_LIVING::nextScene() {


	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_CRDone_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
