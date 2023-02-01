#pragma once
#include "SCENE.h"
class STAGE_KITCHEN :
    public SCENE
{
public:
    STAGE_KITCHEN(class GAME* game);
    ~STAGE_KITCHEN();
    void draw();
    void nextScene();
};