#pragma once
#include"TITLE.h"
#include"GAME_OVER.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		GAME_OVER::DATA GameOver;


	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();
	TITLE::DATA& title() { return Data.title; }
};

