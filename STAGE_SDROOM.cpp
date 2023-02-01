#include"libOne.h"
#include"GAME.h"
#include "STAGE_SDROOM.h"
STAGE_SDROOM::STAGE_SDROOM(class GAME* game) :
	SCENE(game) {

}

STAGE_SDROOM::~STAGE_SDROOM() {
}

void STAGE_SDROOM::draw() {
	clear();
	printSize(50);
	print("STAGE_SDROOM");
}

void STAGE_SDROOM::nextScene() {


	if (isTrigger(KEY_A)) {
		game()->changeScene(GAME::STAGE_CRDsec_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
