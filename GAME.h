#pragma once
class GAME
{
	//ƒRƒ“ƒeƒi
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }

public:
	enum SCENE_ID {
		TITLE_ID,

		STAGE_OUTSIDE_ID,
		STAGE_CRDone_ID,
		STAGE_LIVING_ID,
		STAGE_KITCHEN_ID,
		STAGE_BROOM_ID,
		STAGE_CRDsec_ID,
		STAGE_SDROOM_ID,
		STAGE_BEDROOM_ID,

		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES

	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
public:
	void changeScene(SCENE_ID sceneId);
private:
	class MAP* Map;
	class MAP2* Map2;
	class MAPL* MapL;
	class MAPK* MapK;
	class MAPH* MapH;
	class MAPB* MapB;
	class MAPS* MapS;






public:
	class MAP* map() { return Map; }
	class MAP2* map2() { return Map2; }
	class MAPL* mapL() { return MapL; }
	class MAPK* mapK() { return MapK; }
	class MAPH* mapH() { return MapH; }
	class MAPB* mapB() { return MapB; }
	class MAPS* mapS() { return MapS; }






public:
	GAME();
	~GAME();
	void run();
};