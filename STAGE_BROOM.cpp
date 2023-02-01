#include"libOne.h"
#include"GAME.h"
#include "STAGE_BROOM.h"
STAGE_BROOM::STAGE_BROOM(class GAME* game) :
	SCENE(game) {

}

STAGE_BROOM::~STAGE_BROOM() {
}

void STAGE_BROOM::draw() {
	clear();
	printSize(50);
	print("STAGE_BROOM");
}

void STAGE_BROOM::nextScene() {


	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_CRDone_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
