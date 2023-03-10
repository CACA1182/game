#pragma once
#include "CHARACTER.h"
class ENEMY :
    public CHARACTER
{
public:
    struct DATA {
        int rightAnimId = 0;
        int leftAnimId = 1;
        int upAnimId = 2;
        int downAnimId = 3;


        int rightImg = 0;
        int leftImg = 0;
        int upImg = 0;
        int downImg = 0;

        float curWx = 0;
        float curWy = 0;
        float ex = 0;
        float ey = 0;
        float dashspeed = 0;
        float differenceX = 0;
        float differenceY = 0;
        float sensingOffset = 0;
        int direction = 0;


    };
private:
    DATA Enemy;
    enum class STATE { STRUGGLING, DIED, SURVIVED };
    STATE State = STATE::STRUGGLING;
public:
    ENEMY(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float ewx, float ewy, float vx, float vy);
    void update();
    void init();

    void homing();
private:
public:
    void draw();
    void damage();
    bool died();
    bool survived();
 
};

