#include"GAME.h"
#include"CONTAINER.h"
#include "MAP.h"
MAP::MAP(class GAME* game) :
    GAME_OBJECT(game) {
}
MAP::~MAP() {
    if (Map.data) { delete[] Map.data; Map.data = 0; }
}
void MAP::create() {
    Map = game()->container()->data().map;
}
void MAP::init() {
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, Map.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", Map.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (Map.data) { delete[] Map.data; Map.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    Map.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(Map.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    Map.rows = 0;
    Map.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (Map.data[i] == '\n') {
            if (Map.rows == 0) {
                //�ŏ��̍s�̗�
                Map.cols = cnt;
            }
            else if (Map.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            Map.rows++;
            cnt = 0;
        }
    }
    if (fileSize % Map.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    Map.dispCols = (int)width / Map.chipSize + 1;//�\�����ׂ���
    //����dispRows�K�v

    Map.worldWidth = (float)Map.chipSize * (Map.cols - 2);//���[���h�̉���
    Map.endWorldX = Map.worldWidth - width;//�\���ł���Ō�̍��W
    Map.worldHeight = (float)Map.chipSize * (Map.rows);//���[���h�̏c��
    Map.endWorldY = Map.worldHeight - height;//�\���ł���Ō�̍��W
    Map.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
    Map.wy = 0.0f;//���ݕ\�����Ă��郏�[���h���W

}
void MAP::update() {
    //�v���C���[���ł��Ă���@
    //���͉��ړ�������
    Map.wy += 1;
    if (Map.wy > Map.endWorldY) {
        Map.wy = Map.endWorldY;
    }
    if (Map.wx > Map.endWorldX) {
        Map.wx = Map.endWorldX;
    }
}
void MAP::draw() {
    int startCol = (int)Map.wx / Map.chipSize;//�\���J�n��
    int endCol = startCol + Map.dispCols;//�\���I����
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)Map.chipSize * c;
        for (int r = 0; r < Map.rows; r++) {
            float wy = (float)Map.chipSize * r;
            char charaId = Map.data[r * Map.cols + c];
            //�؂̊G���������閔�͉��Ƀ��N�g��u��
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - Map.wx;
                float py = wy - Map.wy;
                if (charaId == '1') image(Map.blockImg, px, py);
                else if (charaId == '2')image(Map.dublockImg, px, py);
                else if (charaId == '3')image(Map.dnblockImg, px, py);
                else if (charaId == '4')image(Map.wublockImg, px, py);
                else if (charaId == '5')image(Map.wnblockImg, px, py);
                else if (charaId == '6')image(Map.wiublockImg, px, py);
                else if (charaId == '7')image(Map.widblockImg, px, py);
                else if (charaId == '8')image(Map.strblockImg, px, py);
                else if (charaId == '9')image(Map.tileImg, px, py);
                else if (charaId == '0')image(Map.carpet1Img, px, py);
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                float px = wx - Map.wx;
                float py = wy - Map.wy;
                if (charaId == 't')image(Map.wallTImg, px, py);
                else if (charaId == 'b')image(Map.wallBImg, px, py);
                else if (charaId == 'r')image(Map.wallRImg, px, py);
              

                else if (charaId == 'l')image(Map.wallLImg, px, py);
                else if (charaId == 'w')image(Map.wallWImg, px, py);
                else if (charaId == 'd')image(Map.blockdImg, px, py);




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
