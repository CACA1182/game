#pragma once
#include "SCENE.h"
class STAGE_SDROOM :
    public SCENE
{
public:
    STAGE_SDROOM(class GAME* game);
    ~STAGE_SDROOM();
    void init();
    void update();
    void draw();
    void nextScene();
};