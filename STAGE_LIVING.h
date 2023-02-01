#pragma once
#include "SCENE.h"
class STAGE_LIVING :
    public SCENE
{
public:
    STAGE_LIVING(class GAME* game);
    ~STAGE_LIVING();
    void draw();
    void nextScene();
};