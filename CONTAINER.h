#pragma once
#include"TITLE.h"
#include"GAME_OVER.h"

#include"STAGE_CRDone.h"
#include"STAGE_CRDsec.h"
#include"STAGE_KITCHEN.h"
#include"STAGE_LIVING.h"

#include"MAP.h"
#include"MAP2.h"
#include"MAPL.h"
#include"MAPK.h"
#include"MAPH.h"
#include"MAPB.h"
#include"MAPS.h"




class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		GAME_OVER::DATA GameOver;
		MAP::DATA map;
		MAP2::DATA map2;
		MAPL::DATA mapL;
		MAPK::DATA mapK;
		MAPH::DATA mapH;
		MAPB::DATA mapB;
		MAPS::DATA mapS;







	};
	DATA Data;
public:
	void load();
	void setData();
	void LoadGraphic();
	TITLE::DATA& title() { return Data.title; }
	const DATA& data() { return Data; }

};

