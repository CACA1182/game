#include"GAME.h"
#include"PLAYER.h"
#include"CONTAINER.h"
#include "HIT_POINT.h"

HIT_POINT::HIT_POINT(class GAME* game) :
	GAME_OBJECT(game)
{
}

HIT_POINT::~HIT_POINT()
{
}

void HIT_POINT::create()
{
	Hit_point = game()->container()->data().hitpoint;
}

void HIT_POINT::init()
{
	Hit_point.numHitPointContainer = game()->container()->data().hitpoint.numHitPointContainer;
}

void HIT_POINT::draw()
{
	for (int i = 1; i < game()->container()->data().hitpoint.numHitPointContainer + 1; i++) {
		if (game()->characterManager()->player()->hp() >= i * 2) {
		}
		else if (game()->characterManager()->player()->hp() == i * 2 - 1)
		{
		}
		else
		{
		}
	}
}
