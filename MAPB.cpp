#include"GAME.h"
#include"CONTAINER.h"
#include "MAPB.h"
MAPB::MAPB(class GAME* game) :
    GAME_OBJECT(game) {
}
MAPB::~MAPB() {
    if (MapB.data) { delete[] MapB.data; MapB.data = 0; }
}
void MAPB::create() {
    MapB = game()->container()->data().mapB;

}
void MAPB::init() {
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, MapB.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", MapB.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (MapB.data) { delete[] MapB.data; MapB.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    MapB.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(MapB.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    MapB.rows = 0;
    MapB.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (MapB.data[i] == '\n') {
            if (MapB.rows == 0) {
                //�ŏ��̍s�̗�
                MapB.cols = cnt;
            }
            else if (MapB.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            MapB.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapB.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    MapB.dispCols = (int)width / MapB.chipSize + 1;//�\�����ׂ���
    //����dispRows�K�v

    MapB.worldWidth = (float)MapB.chipSize * (MapB.cols - 2);//���[���h�̉���
    MapB.endWorldX = MapB.worldWidth - width;//�\���ł���Ō�̍��W
    MapB.worldHeight = (float)MapB.chipSize * (MapB.rows);//���[���h�̏c��
    MapB.endWorldY = MapB.worldHeight - height;//�\���ł���Ō�̍��W
    MapB.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
    MapB.wy = 0.0f;//���ݕ\�����Ă��郏�[���h���W

}
void MAPB::update() {
    //�v���C���[���ł��Ă���@
    //���͉��ړ�������
    MapB.wy += 1;
    if (MapB.wy > MapB.endWorldY) {
        MapB.wy = MapB.endWorldY;
    }
    if (MapB.wx > MapB.endWorldX) {
        MapB.wx = MapB.endWorldX;
    }
}
void MAPB::draw() {
    int startCol = (int)MapB.wx / MapB.chipSize;//�\���J�n��
    int endCol = startCol + MapB.dispCols;//�\���I����
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapB.chipSize * c;
        for (int r = 0; r < MapB.rows; r++) {
            float wy = (float)MapB.chipSize * r;
            char charaId = MapB.data[r * MapB.cols + c];
            //�؂̊G���������閔�͉��Ƀ��N�g��u��
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - MapB.wx;
                float py = wy - MapB.wy;
                if (charaId == '1') image(MapB.blockImg, px, py);
                else if (charaId == '2')image(MapB.dublockImg, px, py);
                else if (charaId == '3')image(MapB.dnblockImg, px, py);
                else if (charaId == '4')image(MapB.wublockImg, px, py);
                else if (charaId == '5')image(MapB.wnblockImg, px, py);
                else if (charaId == '6')image(MapB.wiublockImg, px, py);
                else if (charaId == '7')image(MapB.widblockImg, px, py);
                else if (charaId == '8')image(MapB.strblockImg, px, py);
                else if (charaId == '9')image(MapB.tileImg, px, py);
                else if (charaId == '0')image(MapB.carpet1Img, px, py);
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                float px = wx - MapB.wx;
                float py = wy - MapB.wy;
                if (charaId == 't')image(MapB.wallTImg, px, py);
                else if (charaId == 'b')image(MapB.wallBImg, px, py);
                else if (charaId == 'r')image(MapB.wallRImg, px, py);


                else if (charaId == 'l')image(MapB.wallLImg, px, py);
                else if (charaId == 'w')image(MapB.wallWImg, px, py);
                else if (charaId == 'd')image(MapB.blockdImg, px, py);




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
