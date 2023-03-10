#include"libOne.h"
#include"GAME.h"
#include"MAP.h"
#include"CONTAINER.h"
#include"CHARACTER_MANAGER.h"
#include "STAGE.h"
STAGE::STAGE(GAME* game) :
	SCENE(game)
{
}

STAGE::~STAGE()
{

}

void STAGE::init()
{
	game()->map()->init();
	game()->characterManager()->init();

}

void STAGE::update()
{
	game()->characterManager()->update();
	game()->map()->update();
}

void STAGE::draw()
{
	clear();
	game()->map()->draw();
	game()->characterManager()->draw();

}

void STAGE::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
	}
	
	
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
	else if (game()->characterManager()->player()->died()) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
	
}
