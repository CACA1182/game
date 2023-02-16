#include"libOne.h"
#include"CONTAINER.h"
#include"GAME.h"
#include "TITLE.h"
TITLE::TITLE(GAME* game) :
	SCENE(game)
{
}

TITLE::~TITLE()
{
}

void TITLE::create()
{
	Title = game()->container()->data().title;
}

void TITLE::draw()
{

	clear();

	rectMode(CENTER);
	image(Title.imgback, 500, 500);
	image(Title.imgHan, Title.pos.x - 200, Title.slc);

	image(Title.imgS, Title.pos.x, Title.pos.y + 200);

	image(Title.imgE, Title.pos.x, Title.pos.y + 300);

}

void TITLE::nextScene()
{
	if (isTrigger(KEY_SPACE) && Title.slc == Title.pos.y + 200) {
		game()->changeScene(GAME::STAGE_ID);
	}
	if (isTrigger(KEY_SPACE) && Title.slc == Title.pos.y + 300) {
		exit(0);
	}

	/*
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::STAGE_ID);
	}
	*/
}
void TITLE::update() {
	if (isTrigger(KEY_W) && Title.slc > Title.pos.y + 299) {
		Title.slc -= Title.vy;
	}

	if (isTrigger(KEY_S) && Title.slc < Title.pos.y + 201) {
		Title.slc += Title.vy;
	}


}

