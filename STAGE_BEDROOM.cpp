#include"libOne.h"
#include"GAME.h"
#include "STAGE_BEDROOM.h"
STAGE_BEDROOM::STAGE_BEDROOM(class GAME* game) :
	SCENE(game) {

}

STAGE_BEDROOM::~STAGE_BEDROOM() {
}

void STAGE_BEDROOM::draw() {
	clear();
	printSize(50);
	print("STAGE_BEDROOM");
}

void STAGE_BEDROOM::nextScene() {


	if (isTrigger(KEY_A)) {
		game()->changeScene(GAME::STAGE_CRDsec_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
