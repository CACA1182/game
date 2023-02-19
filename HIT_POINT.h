#pragma once
#include "CHARACTER.h"
class HIT_POINT :
    public GAME_OBJECT
{
public:
    struct DATA {
      
        float px = 0;
        float py = 0;
        float offSetPx = 0;
        int numHitPointContainer = 0;
    };
private:
    DATA Hit_point;
public:
    HIT_POINT(class GAME* game);
    ~HIT_POINT();
    void create();
    void init();
    void draw();
};

