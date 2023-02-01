#pragma once
#include "SCENE.h"
class STAGE_OUTSIDE :
    public SCENE
{
public:
    STAGE_OUTSIDE(class GAME* game);
    ~STAGE_OUTSIDE();
    void draw();
    void nextScene();
};

