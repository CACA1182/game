#include"libOne.h"
#include"GAME.h"
#include "GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(GAME* game) :
	SCENE(game)
{
}

GAME_CLEAR::~GAME_CLEAR()
{
}

void GAME_CLEAR::draw()
{
	clear();
	//image(GameClear.cimg, 500, 500);
	textSize(100);
	fill(255);
	print("CLEAR");
	print("SPACE‚ÅØ‚è‘Ö‚¦");
}

void GAME_CLEAR::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
