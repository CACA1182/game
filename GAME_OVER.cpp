#include"libOne.h"
#include"GAME.h"
#include "GAME_OVER.h"
GAME_OVER::GAME_OVER(GAME* game) :
	SCENE(game)
{
}

GAME_OVER::~GAME_OVER()
{
}

void GAME_OVER::draw()
{
	rectMode(CENTER);
	image(GameOver.img, 500, 500);
	fill(0);
	textSize(30);
	text("SPACE‚Åƒ^ƒCƒgƒ‹‚É–ß‚é", 0, 1000);

}

void GAME_OVER::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
