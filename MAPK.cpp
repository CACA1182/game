#include"GAME.h"
#include"CONTAINER.h"
#include "MAPK.h"
MAPK::MAPK(class GAME* game) :
    GAME_OBJECT(game) {
}
MAPK::~MAPK() {
    if (MapK.data) { delete[] MapK.data; MapK.data = 0; }
}
void MAPK::create() {
    MapK = game()->container()->data().mapK;

}
void MAPK::init() {
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, MapK.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", MapK.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (MapK.data) { delete[] MapK.data; MapK.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    MapK.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(MapK.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    MapK.rows = 0;
    MapK.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (MapK.data[i] == '\n') {
            if (MapK.rows == 0) {
                //�ŏ��̍s�̗�
                MapK.cols = cnt;
            }
            else if (MapK.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            MapK.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapK.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    MapK.dispCols = (int)width / MapK.chipSize + 1;//�\�����ׂ���
    //����dispRows�K�v

    MapK.worldWidth = (float)MapK.chipSize * (MapK.cols - 2);//���[���h�̉���
    MapK.endWorldX = MapK.worldWidth - width;//�\���ł���Ō�̍��W
    MapK.worldHeight = (float)MapK.chipSize * (MapK.rows);//���[���h�̏c��
    MapK.endWorldY = MapK.worldHeight - height;//�\���ł���Ō�̍��W
    MapK.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
    MapK.wy = 0.0f;//���ݕ\�����Ă��郏�[���h���W

}
void MAPK::update() {
    //�v���C���[���ł��Ă���@
    //���͉��ړ�������
    MapK.wy += 1;
    if (MapK.wy > MapK.endWorldY) {
        MapK.wy = MapK.endWorldY;
    }
    if (MapK.wx > MapK.endWorldX) {
        MapK.wx = MapK.endWorldX;
    }
}
void MAPK::draw() {
    int startCol = (int)MapK.wx / MapK.chipSize;//�\���J�n��
    int endCol = startCol + MapK.dispCols;//�\���I����
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapK.chipSize * c;
        for (int r = 0; r < MapK.rows; r++) {
            float wy = (float)MapK.chipSize * r;
            char charaId = MapK.data[r * MapK.cols + c];
            //�؂̊G���������閔�͉��Ƀ��N�g��u��
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - MapK.wx;
                float py = wy - MapK.wy;
                if (charaId == '1') image(MapK.blockImg, px, py);
                else if (charaId == '2')image(MapK.dublockImg, px, py);
                else if (charaId == '3')image(MapK.dnblockImg, px, py);
                else if (charaId == '4')image(MapK.wublockImg, px, py);
                else if (charaId == '5')image(MapK.wnblockImg, px, py);
                else if (charaId == '6')image(MapK.wiublockImg, px, py);
                else if (charaId == '7')image(MapK.widblockImg, px, py);
                else if (charaId == '8')image(MapK.strblockImg, px, py);
                else if (charaId == '9')image(MapK.tileImg, px, py);
                else if (charaId == '0')image(MapK.carpet1Img, px, py);
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                float px = wx - MapK.wx;
                float py = wy - MapK.wy;
                if (charaId == 't')image(MapK.wallTImg, px, py);
                else if (charaId == 'b')image(MapK.wallBImg, px, py);
                else if (charaId == 'r')image(MapK.wallRImg, px, py);


                else if (charaId == 'l')image(MapK.wallLImg, px, py);
                else if (charaId == 'w')image(MapK.wallWImg, px, py);
                else if (charaId == 'd')image(MapK.blockdImg, px, py);




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
