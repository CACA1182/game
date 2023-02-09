#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"MAPS.h"
#include "STAGE_SDROOM.h"
STAGE_SDROOM::STAGE_SDROOM(class GAME* game) :
	SCENE(game) {

}

STAGE_SDROOM::~STAGE_SDROOM() {

}

void  STAGE_SDROOM::init() {
	game()->mapS()->init();

}

void STAGE_SDROOM::update() {
	game()->mapS()->update();

}

void STAGE_SDROOM::draw() {

	clear();
	game()->mapS()->draw();
	printSize(40);
	print("STAGE_SDROOM A X");
}
void STAGE_SDROOM::nextScene() {


	if (isTrigger(KEY_A)) {
		game()->changeScene(GAME::STAGE_CRDsec_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
