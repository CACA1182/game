#pragma once
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    TITLE(class GAME* game);
        ~TITLE();
        void draw();
        void nextScene();
};

