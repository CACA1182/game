#pragma once
#include "GAME_OBJECT.h"
class MAPB :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* fileName = 0;
        int blockImg = 0;   //床
        int dublockImg = 0; //ドア上
        int dnblockImg = 0; //ドア下
        int wublockImg = 0; //壁上
        int wnblockImg = 0; //壁下
        int wiublockImg = 0;//窓上
        int widblockImg = 0;//窓下
        int strblockImg = 0;//階段
        int carpet1Img = 0;//カーペット
        int tileImg = 0;//タイル


        int wallTImg = 0;//kabe
        int wallBImg = 0;//kabe
        int wallRImg = 0;//kabe
        int wallLImg = 0;//kabe
        int wallWImg = 0;//kabe
        int blockdImg = 0;//kabe











        int chipSize = 0; //正方形マップチップ画像の一辺のドット数
        char* data = 0; //データ配列のポインタ
        int cols = 0; //データの列数
        int rows = 0; //データの行数
        int dispCols = 0;
        int dispRows = 0;
        float wx = 0;//world position x
        float wy = 0;//world position y
        float worldWidth = 0;
        float worldHeight = 0;
        float endWorldX = 0;
        float endWorldY = 0;
        float centerX = 0;
        float centerY = 0;
    };
private:
    DATA MapB;
public:
    MAPB(class GAME* game);
    ~MAPB();
    void create();
    void init();
    void update();
    void draw();
    float wx() { return MapB.wx; }
    float wy() { return MapB.wy; }
    int chipSize() { return MapB.chipSize; }

    /*
    //ウィンドウ枠からのはみだし判定用---------------------------------------------------
    float wDispLeft();
    float wDispRight();
    float wDispTop();
    float wDispbottom();
    */
};

