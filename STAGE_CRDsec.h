#pragma once
#include "SCENE.h"
class STAGE_CRDsec :
    public SCENE
{

public:
    STAGE_CRDsec(class GAME* game);
    ~STAGE_CRDsec();
    void init();
    void update();
    void draw();
    void nextScene();


};