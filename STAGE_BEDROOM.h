#pragma once
#include "SCENE.h"
class STAGE_BEDROOM :
    public SCENE
{
public:
    STAGE_BEDROOM(class GAME* game);
    ~STAGE_BEDROOM();
    void init();
    void update();
    void draw();
    void nextScene();
};