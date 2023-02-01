#include"libOne.h"
#include"GAME.h"
#include "STAGE_CRDone.h"
STAGE_CRDone::STAGE_CRDone(class GAME* game) :
	SCENE(game) {

}

STAGE_CRDone::~STAGE_CRDone() {
}

void STAGE_CRDone::draw() {
	clear();
	printSize(40);
	print("STAGE_CRDone A二階KキッチンLリビングB風呂Xオーバー");
}

void STAGE_CRDone::nextScene() {


	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_OUTSIDE_ID);
	}
	else if (isTrigger(KEY_K)) {
		game()->changeScene(GAME::STAGE_KITCHEN_ID);
	}
	else if (isTrigger(KEY_L)) {
		game()->changeScene(GAME::STAGE_LIVING_ID);
	}
	else if (isTrigger(KEY_A)) {
		game()->changeScene(GAME::STAGE_CRDsec_ID);
	}
	else if (isTrigger(KEY_B)) {
		game()->changeScene(GAME::STAGE_BROOM_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
