#include"libOne.h"
#include"TITLE.h"
#include"CONTAINER.h"

#include"STAGE_OUTSIDE.h"
#include"STAGE_CRDone.h"
#include"STAGE_LIVING.h"
#include"STAGE_KITCHEN.h"
#include"STAGE_BROOM.h"
#include"STAGE_CRDsec.h"
#include"STAGE_SDROOM.h"
#include"STAGE_BEDROOM.h"


#include"MAP.h"
#include"MAP2.h"
#include"MAPL.h"
#include"MAPK.h"
#include"MAPH.h"
#include"MAPB.h"
#include"MAPS.h"




#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"GAME.h"
GAME::GAME() {
	Container = new CONTAINER();
	Scenes[TITLE_ID] = new TITLE(this);//タイトル

	Scenes[STAGE_OUTSIDE_ID] = new STAGE_OUTSIDE(this);//庭
	Scenes[STAGE_CRDone_ID] = new STAGE_CRDone(this);//一階廊下
	Scenes[STAGE_LIVING_ID] = new STAGE_LIVING(this);//リビング（和室）
	Scenes[STAGE_KITCHEN_ID] = new STAGE_KITCHEN(this);//キッチン
	Scenes[STAGE_BROOM_ID] = new STAGE_BROOM(this);//風呂
	Scenes[STAGE_CRDsec_ID] = new STAGE_CRDsec(this);//二階廊下
	Scenes[STAGE_SDROOM_ID] = new STAGE_SDROOM(this);//書斎（二階）
	Scenes[STAGE_BEDROOM_ID] = new STAGE_BEDROOM(this);//寝室(二階)


	Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
	Scenes[GAME_OVER_ID] = new GAME_OVER(this);

	CurSceneId = TITLE_ID;
	Map = new MAP(this);
	Map2 = new MAP2(this);
	MapL = new MAPL(this);
	MapK = new MAPK(this);
	MapH = new MAPH(this);
	MapB = new MAPB(this);
	MapS = new MAPS(this);





}
GAME::~GAME(){
	delete Map;
	delete Map2;
	delete MapL;
	delete MapK;
	delete MapH;
	delete MapB;
	delete MapS;






	for (int i = 0; i < NUM_SCENES;i++) {
		delete Scenes[i];
	}
	
}
void GAME::run() {
	window(1000, 1000, full);

	Container->load();
	Scenes[TITLE_ID]->create();
	Map->create();
	Map2->create();
	MapL->create();
	MapK->create();
	MapH->create();
	MapB->create();
	MapS->create();






	CurSceneId = TITLE_ID;
	Scenes[CurSceneId]->init();
	while (notQuit) {
		Scenes[CurSceneId]->proc();
	}
}
void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
	Scenes[CurSceneId]->init();

	//次ページ 廊下一階
	if (isTrigger(KEY_Z)) {
		CurSceneId = sceneId;
	}
	//廊下二階
	if (isTrigger(KEY_A)) {
		CurSceneId = sceneId;
	}
	//キッチン
	if (isTrigger(KEY_K)) {
		CurSceneId = sceneId;
	}
	//ゲームオーバー
	if (isTrigger(KEY_X)) {
		CurSceneId = sceneId;
	}
	//クリア
	if (isTrigger(KEY_C)) {
		CurSceneId = sceneId;
	}
	//リビング
	if (isTrigger(KEY_L)) {
		CurSceneId = sceneId;
	}
	//風呂
	if (isTrigger(KEY_B)) {
		CurSceneId = sceneId;
	}
	//書斎
	if (isTrigger(KEY_S)) {
		CurSceneId = sceneId;
	}
	//寝室
	if (isTrigger(KEY_D)) {
		CurSceneId = sceneId;
	}
	if (isTrigger(KEY_SPACE)) {
		CurSceneId = sceneId;
	}
}