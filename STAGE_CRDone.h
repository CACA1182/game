#pragma once
#include "SCENE.h"
class STAGE_CRDone :
    public SCENE
{
public:
    STAGE_CRDone(class GAME* game);
    ~STAGE_CRDone();
    void draw();
    void nextScene();
};