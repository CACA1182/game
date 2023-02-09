#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"MAPL.h"
#include "STAGE_LIVING.h"
STAGE_LIVING::STAGE_LIVING(class GAME* game) :
	SCENE(game) {

}

STAGE_LIVING::~STAGE_LIVING() {

}

void  STAGE_LIVING::init() {
	game()->mapL()->init();

}

void STAGE_LIVING::update() {
	game()->mapL()->update();

}

void STAGE_LIVING::draw() {

	clear();
	game()->mapL()->draw();
	printSize(40);
	print("STAGE_LIVING Z X");
}
void STAGE_LIVING::nextScene() {


	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_CRDone_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}

}
