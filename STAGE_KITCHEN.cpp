#include"libOne.h"
#include"GAME.h"
#include "STAGE_KITCHEN.h"
STAGE_KITCHEN::STAGE_KITCHEN(class GAME* game) :
	SCENE(game) {

}

STAGE_KITCHEN::~STAGE_KITCHEN() {
}

void STAGE_KITCHEN::draw() {
	clear();
	printSize(50);
	print("STAGE_KITCHEN");
}

void STAGE_KITCHEN::nextScene() {


	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_CRDone_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
