#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"MAP2.h"
#include "STAGE_CRDsec.h"
STAGE_CRDsec::STAGE_CRDsec(class GAME* game) :
	SCENE(game) {

}

STAGE_CRDsec::~STAGE_CRDsec() {

}

void  STAGE_CRDsec::init() {
	game()->map2()->init();

}

void STAGE_CRDsec::update() {
	game()->map2()->update();

}

void STAGE_CRDsec::draw() {

	clear();
	game()->map2()->draw();
	printSize(40);
	print("STAGE_CRDone A二階KキッチンLリビングB風呂Xオーバー");
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
