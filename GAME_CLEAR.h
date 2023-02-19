#pragma once
#include "SCENE.h"
class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA
    {
        
        int cimg;


    };
private:
    DATA GameClear;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void draw();
    void nextScene();
};

