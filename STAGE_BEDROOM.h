#pragma once
#include "SCENE.h"
class STAGE_BEDROOM :
    public SCENE
{
public:
    STAGE_BEDROOM(class GAME* game);
    ~STAGE_BEDROOM();
    void draw();
    void nextScene();
};