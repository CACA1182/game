#include"libOne.h"
#include"CONTAINER.h"
#include"GAME.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game) :
	SCENE(game){
	
}

TITLE::~TITLE(){
	

}
void TITLE::create() {
	Title = game()->container()->title();
}

void TITLE::draw(){

	clear();
	
	rectMode(CENTER);
	image(Title.imgHan,Title.pos.x-200,Title.slc);
	rect(Title.pos.x, Title.pos.y+300, Title.w, Title.h);
	rect(Title.pos.x, Title.pos.y+200, Title.w, Title.h);

}

void TITLE::nextScene() {

		if (isTrigger(KEY_SPACE)&&Title.slc==Title.pos.y+200) {
			game()->changeScene(GAME::STAGE_OUTSIDE_ID);
		}
		if (isTrigger(KEY_SPACE) && Title.slc == Title.pos.y + 300) {
			exit(0);
		}

	
	
/*
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_OUTSIDE_ID);
	}
*/	
	
}

void TITLE::update() {
	if (isTrigger(KEY_W)&& Title.slc > Title.pos.y + 299) {
		Title.slc -= Title.vy;
	}

	if (isTrigger(KEY_S)&& Title.slc < Title.pos.y + 201) {
		Title.slc += Title.vy;
	}

	
}
