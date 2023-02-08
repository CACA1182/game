#include"GAME.h"
#include"CONTAINER.h"
#include "MAP.h"
MAP2::MAP2(class GAME* game) :
    GAME_OBJECT(game) {
}
MAP2::~MAP2() {
    if (Map2.data) { delete[] Map2.data; Map2.data = 0; }
}
void MAP2::create() {
    Map2 = game()->container()->data().map2;
}
void MAP2::init() {
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, Map2.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", Map2.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (Map2.data) { delete[] Map2.data; Map2.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    Map2.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(Map2.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    Map2.rows = 0;
    Map2.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (Map2.data[i] == '\n') {
            if (Map2.rows == 0) {
                //�ŏ��̍s�̗�
                Map2.cols = cnt;
            }
            else if (Map2.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            Map2.rows++;
            cnt = 0;
        }
    }
    if (fileSize % Map2.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    Map2.dispCols = (int)width / Map2.chipSize + 1;//�\�����ׂ���
    //����dispRows�K�v

    Map2.worldWidth = (float)Map2.chipSize * (Map2.cols - 2);//���[���h�̉���
    Map2.endWorldX = Map2.worldWidth - width;//�\���ł���Ō�̍��W
    Map2.worldHeight = (float)Map2.chipSize * (Map2.rows);//���[���h�̏c��
    Map2.endWorldY = Map2.worldHeight - height;//�\���ł���Ō�̍��W
    Map2.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
    Map2.wy = 0.0f;//���ݕ\�����Ă��郏�[���h���W

}
void MAP2::update() {
    //�v���C���[���ł��Ă���@
    //���͉��ړ�������
    Map2.wy += 1;
    if (Map2.wy > Map2.endWorldY) {
        Map2.wy = Map2.endWorldY;
    }
    if (Map2.wx > Map2.endWorldX) {
        Map2.wx = Map2.endWorldX;
    }
}
void MAP2::draw() {
    int startCol = (int)Map2.wx / Map2.chipSize;//�\���J�n��
    int endCol = startCol + Map2.dispCols;//�\���I����
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)Map2.chipSize * c;
        for (int r = 0; r < Map2.rows; r++) {
            float wy = (float)Map2.chipSize * r;
            char charaId = Map2.data[r * Map2.cols + c];
            //�؂̊G���������閔�͉��Ƀ��N�g��u��
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - Map2.wx;
                float py = wy - Map2.wy;
                if (charaId == '1') image(Map2.blockImg, px, py);
                else if (charaId == '2')image(Map2.dublockImg, px, py);
                else if (charaId == '3')image(Map2.dnblockImg, px, py);
                else if (charaId == '4')image(Map2.wublockImg, px, py);
                else if (charaId == '5')image(Map2.wnblockImg, px, py);
                else if (charaId == '6')image(Map2.wiublockImg, px, py);
                else if (charaId == '7')image(Map2.widblockImg, px, py);
                else if (charaId == '8')image(Map2.strblockImg, px, py);
                else if (charaId == '9')image(Map2.tileImg, px, py);
                else if (charaId == '0')image(Map2.carpet1Img, px, py);
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                float px = wx - Map2.wx;
                float py = wy - Map2.wy;
                if (charaId == 't')image(Map2.wallTImg, px, py);
                else if (charaId == 'b')image(Map2.wallBImg, px, py);
                else if (charaId == 'r')image(Map2.wallRImg, px, py);


                else if (charaId == 'l')image(Map2.wallLImg, px, py);
                else if (charaId == 'w')image(Map2.wallWImg, px, py);
                else if (charaId == 'd')image(Map2.blockdImg, px, py);




            }



        }
    }
}
/*
float MAP::wDispLeft()
{
    return Map.wx - Map.chipSize;
}

float MAP::wDispRight()
{
    return Map.wx + width;
}

float MAP::wDispTop()
{
    return Map.wy - Map.chipSize;
}

float MAP::wDispbottom()
{
    return Map.wy + height;
}


*/
