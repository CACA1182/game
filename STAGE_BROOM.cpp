#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"MAPH.h"
#include "STAGE_BROOM.h"
STAGE_BROOM::STAGE_BROOM(class GAME* game) :
	SCENE(game) {

}

STAGE_BROOM::~STAGE_BROOM() {

}

void  STAGE_BROOM::init() {
	game()->mapH()->init();

}

void STAGE_BROOM::update() {
	game()->mapH()->update();

}

void STAGE_BROOM::draw() {

	clear();
	game()->mapH()->draw();
	printSize(40);
	print("STAGE_CRDone Z X");
}

void STAGE_BROOM::nextScene() {


	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_CRDone_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
