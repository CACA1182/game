#include"libOne.h"
#include"GAME.h"
#include "STAGE_CRDsec.h"
STAGE_CRDsec::STAGE_CRDsec(class GAME* game) :
	SCENE(game) {

}

STAGE_CRDsec::~STAGE_CRDsec() {
}

void STAGE_CRDsec::draw() {
	clear();
	printSize(50);
	print("STAGE_CRDsec ZˆêŠKS‘ÖDQŽº");
}

void STAGE_CRDsec::nextScene() {


	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_CRDone_ID);
	}
	else if (isTrigger(KEY_S)) {
		game()->changeScene(GAME::STAGE_SDROOM_ID);
	}
	else if (isTrigger(KEY_D)) {
		game()->changeScene(GAME::STAGE_BEDROOM_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
