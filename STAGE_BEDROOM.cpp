#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"MAPB.h"
#include "STAGE_BEDROOM.h"
STAGE_BEDROOM::STAGE_BEDROOM(class GAME* game) :
	SCENE(game) {

}

STAGE_BEDROOM::~STAGE_BEDROOM() {

}

void  STAGE_BEDROOM::init() {
	game()->mapB()->init();

}

void STAGE_BEDROOM::update() {
	game()->mapB()->update();

}

void STAGE_BEDROOM::draw() {

	clear();
	game()->mapB()->draw();
	printSize(40);
	print("STAGE_BEDROOM A X");
}
void STAGE_BEDROOM::nextScene() {


	if (isTrigger(KEY_A)) {
		game()->changeScene(GAME::STAGE_CRDsec_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
