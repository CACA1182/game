#include"libOne.h"
#include"GAME.h"
#include "STAGE.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game){

}

STAGE::~STAGE() {
}

void STAGE::draw() {
	clear();
	printSize(50);
	print("STAGE");
}

void STAGE::nextScene() {
	
	if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
	else if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
	}
	
}
