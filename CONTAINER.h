#pragma once
#include"TITLE.h"
#include"MAP.h"
#include"PLAYER.h"
#include"ENEMY.h"
#include"CHARACTER_MANAGER.h"
#include"GAME_OVER.h"
#include"HIT_POINT.h"
#include"GAME_CLEAR.h"


class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		GAME_OVER::DATA GameOver;

		GAME_CLEAR::DATA GameClear;
		MAP::DATA map;

		CHARACTER::DATA enemyChara;
		ENEMY::DATA enemy;
		CHARACTER::DATA playerChara;
		PLAYER::DATA player;

		CHARACTER_MANAGER::DATA charaMng;
		HIT_POINT::DATA hitpoint;

	};
	DATA Data;
public:
	void load();
	void setData();//privateにしても大丈夫か？
	void LoadGraphics();//privateにしても大丈夫か？
	const DATA& data() { return Data; }
};

