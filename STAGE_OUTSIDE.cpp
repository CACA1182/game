#include"libOne.h"
#include"GAME.h"
#include "STAGE_OUTSIDE.h"
STAGE_OUTSIDE::STAGE_OUTSIDE(class GAME* game) :
	SCENE(game){

}

STAGE_OUTSIDE::~STAGE_OUTSIDE() {
}

void STAGE_OUTSIDE::draw() {
	clear();
	printSize(50);
	print("STAGE_OUTSIDE Z��KC�N���A");
}

void STAGE_OUTSIDE::nextScene() {
	





	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_CRDone_ID);
	}
	
	else if (isTrigger(KEY_C)) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
	}
	
}
