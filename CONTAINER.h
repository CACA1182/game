#pragma once
#include"TITLE.h"
#include"MAP.h"
#include"PLAYER.h"
#include"CHARACTER_MANAGER.h"
#include"GAME_OVER.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		GAME_OVER::DATA GameOver;

		MAP::DATA map;
		CHARACTER::DATA playerChara;
		PLAYER::DATA player;
		CHARACTER_MANAGER::DATA charaMng;
	};
	DATA Data;
public:
	void load();
	void setData();//private�ɂ��Ă����v���H
	void LoadGraphics();//private�ɂ��Ă����v���H
	const DATA& data() { return Data; }
};

