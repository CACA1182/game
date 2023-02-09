#include"GAME.h"
#include"CONTAINER.h"
#include "MAPH.h"
MAPH::MAPH(class GAME* game) :
    GAME_OBJECT(game) {
}
MAPH::~MAPH() {
    if (MapH.data) { delete[] MapH.data; MapH.data = 0; }
}
void MAPH::create() {
    MapH = game()->container()->data().mapH;

}
void MAPH::init() {
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, MapH.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", MapH.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (MapH.data) { delete[] MapH.data; MapH.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    MapH.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(MapH.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    MapH.rows = 0;
    MapH.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (MapH.data[i] == '\n') {
            if (MapH.rows == 0) {
                //�ŏ��̍s�̗�
                MapH.cols = cnt;
            }
            else if (MapH.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            MapH.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapH.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    MapH.dispCols = (int)width / MapH.chipSize + 1;//�\�����ׂ���
    //����dispRows�K�v

    MapH.worldWidth = (float)MapH.chipSize * (MapH.cols - 2);//���[���h�̉���
    MapH.endWorldX = MapH.worldWidth - width;//�\���ł���Ō�̍��W
    MapH.worldHeight = (float)MapH.chipSize * (MapH.rows);//���[���h�̏c��
    MapH.endWorldY = MapH.worldHeight - height;//�\���ł���Ō�̍��W
    MapH.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
    MapH.wy = 0.0f;//���ݕ\�����Ă��郏�[���h���W

}
void MAPH::update() {
    //�v���C���[���ł��Ă���@
    //���͉��ړ�������
    MapH.wy += 1;
    if (MapH.wy > MapH.endWorldY) {
        MapH.wy = MapH.endWorldY;
    }
    if (MapH.wx > MapH.endWorldX) {
        MapH.wx = MapH.endWorldX;
    }
}
void MAPH::draw() {
    int startCol = (int)MapH.wx / MapH.chipSize;//�\���J�n��
    int endCol = startCol + MapH.dispCols;//�\���I����
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapH.chipSize * c;
        for (int r = 0; r < MapH.rows; r++) {
            float wy = (float)MapH.chipSize * r;
            char charaId = MapH.data[r * MapH.cols + c];
            //�؂̊G���������閔�͉��Ƀ��N�g��u��
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - MapH.wx;
                float py = wy - MapH.wy;
                if (charaId == '1') image(MapH.blockImg, px, py);
                else if (charaId == '2')image(MapH.dublockImg, px, py);
                else if (charaId == '3')image(MapH.dnblockImg, px, py);
                else if (charaId == '4')image(MapH.wublockImg, px, py);
                else if (charaId == '5')image(MapH.wnblockImg, px, py);
                else if (charaId == '6')image(MapH.wiublockImg, px, py);
                else if (charaId == '7')image(MapH.widblockImg, px, py);
                else if (charaId == '8')image(MapH.strblockImg, px, py);
                else if (charaId == '9')image(MapH.tileImg, px, py);
                else if (charaId == '0')image(MapH.carpet1Img, px, py);
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                float px = wx - MapH.wx;
                float py = wy - MapH.wy;
                if (charaId == 't')image(MapH.wallTImg, px, py);
                else if (charaId == 'b')image(MapH.wallBImg, px, py);
                else if (charaId == 'r')image(MapH.wallRImg, px, py);


                else if (charaId == 'l')image(MapH.wallLImg, px, py);
                else if (charaId == 'w')image(MapH.wallWImg, px, py);
                else if (charaId == 'd')image(MapH.blockdImg, px, py);




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
