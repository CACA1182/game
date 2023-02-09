#pragma once
#include "SCENE.h"
class STAGE_KITCHEN :
    public SCENE
{

public:
    STAGE_KITCHEN(class GAME* game);
    ~STAGE_KITCHEN();
    void init();
    void update();
    void draw();
    void nextScene();


};