#pragma once
class GAME
{
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE_OUTSIDE_ID,
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