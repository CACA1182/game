#pragma once
class GAME
{
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
	GAME();
	~GAME();
	void run();
	void changeScene(SCENE_ID sceneId);
};