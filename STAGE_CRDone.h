#pragma once
#include "SCENE.h"
class STAGE_CRDone :
    public SCENE
{

public:
    STAGE_CRDone(class GAME* game);
    ~STAGE_CRDone();
    void init();
    void update();
    void draw();
    void nextScene();
 

};