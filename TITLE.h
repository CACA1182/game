#pragma once
#include "SCENE.h"
#include"libOne.h"
class TITLE :
    public SCENE
{

public:
    struct DATA
    {
        VECTOR2 pos;

        int imgS;
        int imgE;
        int imgHan;
        int slc;
        int vx ;
        int vy ;
        int w ;
        int h ;

    };
private:
    DATA Title;

public:
    TITLE(class GAME* game);
        ~TITLE();
        void create();
        void draw();
        void nextScene();
        void update();
};

