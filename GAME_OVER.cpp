#include"libOne.h"
#include"GAME.h"
#include "GAME_OVER.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game){

}
GAME_OVER::~GAME_OVER() {
}
void GAME_OVER::draw() {
	clear();
	printSize(50);
	print("GAME OVER");
}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
