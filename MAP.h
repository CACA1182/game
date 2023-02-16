#pragma once
#include "GAME_OBJECT.h"
class MAP :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* fileName = 0;
        //�u���b�N---------
        int blockImg = 0;
        int dupblock = 0;
        int ddnblock = 0;
        int wallup = 0;
        int walldn = 0;
        int tile = 0;
        int cp = 0;
        int stair = 0;
        int blockd = 0;
        int blockr = 0;
        int wallL = 0;
        int wallR = 0;
        int wallRL = 0;
        int wallT = 0;
        int wallTR = 0;
        int wallTL = 0;


       // ---------------
        int chipSize = 0; //�����`�}�b�v�`�b�v�摜�̈�ӂ̃h�b�g��
        char* data = 0; //�f�[�^�z��̃|�C���^
        int cols = 0; //�f�[�^�̗�
        int rows = 0; //�f�[�^�̍s��
        int dispCols = 0;
        int dispRows = 0;
        float wx = 0;//world position x
        float wy = 0;//world position y
        float worldWidth = 0;
        float worldHeight = 0;
        float startWorldX = 0;
        float startWorldY = 0;
        float endWorldX = 0;
        float endWorldY = 0;
        float centerX = 0;
        float centerY = 0;
    };
    enum CHARA_ID {
        PLAYER_ID = 'a',
    };
private:
    DATA Map;
public:
    MAP(class GAME* game);
    ~MAP();
    void create();
    void init();
    void update();
    void draw();
    float wx() { return Map.wx; }
    float wy() { return Map.wy; }
    int chipSize() { return Map.chipSize; }
    //�}�b�v�`�b�v�ƃL�����̓����蔻��Ɏg�p����֐��Q---------------------------------------
    bool collisionCheck(float wx, float wy);//���̓����蔻��֐��Q����Ăяo���Ďg���֐�
    bool collisionCharaLeft(float wx, float wy);
    bool collisionCharaRight(float wx, float wy);
    bool collisionCharaTop(float wx, float wy);
    bool collisionCharaBottom(float wx, float wy);

    //�E�B���h�E�g����݂̂͂�������p---------------------------------------------------
    float wDispLeft();
    float wDispRight();
    float wDispTop();
    float wDispbottom();
};

