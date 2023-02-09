#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"MAPK.h"
#include "STAGE_KITCHEN.h"
STAGE_KITCHEN::STAGE_KITCHEN(class GAME* game) :
	SCENE(game) {

}

STAGE_KITCHEN::~STAGE_KITCHEN() {

}

void  STAGE_KITCHEN::init() {
	game()->mapK()->init();

}

void STAGE_KITCHEN::update() {
	game()->mapK()->update();

}

void STAGE_KITCHEN::draw() {

	clear();
	game()->mapK()->draw();
	printSize(40);
	print("STAGE_KITCHEN Z X");
}

void STAGE_KITCHEN::nextScene() {


	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_CRDone_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
