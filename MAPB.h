#pragma once
#include "GAME_OBJECT.h"
class MAPB :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* fileName = 0;
        int blockImg = 0;   //��
        int dublockImg = 0; //�h�A��
        int dnblockImg = 0; //�h�A��
        int wublockImg = 0; //�Ǐ�
        int wnblockImg = 0; //�ǉ�
        int wiublockImg = 0;//����
        int widblockImg = 0;//����
        int strblockImg = 0;//�K�i
        int carpet1Img = 0;//�J�[�y�b�g
        int tileImg = 0;//�^�C��


        int wallTImg = 0;//kabe
        int wallBImg = 0;//kabe
        int wallRImg = 0;//kabe
        int wallLImg = 0;//kabe
        int wallWImg = 0;//kabe
        int blockdImg = 0;//kabe











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
    //�E�B���h�E�g����݂̂͂�������p---------------------------------------------------
    float wDispLeft();
    float wDispRight();
    float wDispTop();
    float wDispbottom();
    */
};

