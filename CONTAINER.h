#pragma once
#include"TITLE.h"
#include"GAME_OVER.h"
#include"STAGE_CRDone.h"
#include"MAP.h"
#include"MAP2.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		GAME_OVER::DATA GameOver;
		MAP::DATA map;
		MAP2::DATA map2;


	};
	DATA Data;
public:
	void load();
	void setData();
	void LoadGraphic();
	TITLE::DATA& title() { return Data.title; }
	const DATA& data() { return Data; }

};

