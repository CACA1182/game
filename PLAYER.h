#pragma once
#include "CHARACTER.h"
class PLAYER :
    public CHARACTER
{
public:
    struct DATA {
        int rightAnimId = 0;
        int leftAnimId = 1;
        int upAnimId = 2;
        int downAnimId = 3;
        float curWx = 0;
        float curWy = 0;
        int jumpFlag = 0;
        float px = 0;
        float py = 0;
        int UPimg = 0;
        int DNimg = 0;
        int Rimg = 0;
        int Limg = 0;


    };
private:
    DATA Player;
    enum class STATE { STRUGGLING, DIED, SURVIVED };
    STATE State = STATE::STRUGGLING;
public:
    PLAYER(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void init();
private:
    void Launch();
    void Move();
    void CollisionWithMap();
    void CheckState();
public:
    void draw();
    void damage();
    bool died();
    bool survived();
    float overCenterVx();
    float overCenterVy();
    int hp() { return Chara.hp; }
      float px() { return Player.px; }
    float py() { return Player.py; }
};

