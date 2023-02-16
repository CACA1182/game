#pragma once
#include "SCENE.h"
#include"libOne.h"
class GAME_OVER :
    public SCENE
{
public:
    struct DATA
    {
        VECTOR2 pos;
        int img;


    };
private:
    DATA GameOver;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void draw();
    void nextScene();
};

