#pragma once
#include "SCENE.h"
class STAGE_BROOM :
    public SCENE
{
public:
    STAGE_BROOM(class GAME* game);
    ~STAGE_BROOM();
    void draw();
    void nextScene();
    void init();
    void update();
    

};