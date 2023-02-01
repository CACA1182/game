#include"libOne.h"
#include"GAME.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game) :
	SCENE(game){

}

TITLE::~TITLE(){
}

void TITLE::draw(){
	clear();
	printSize(50);
	print("Title");
}

void TITLE::nextScene() {
	
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_ID);
	}
	
}
