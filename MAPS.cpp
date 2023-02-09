#include"GAME.h"
#include"CONTAINER.h"
#include "MAPS.h"
MAPS::MAPS(class GAME* game) :
    GAME_OBJECT(game) {
}
MAPS::~MAPS() {
    if (MapS.data) { delete[] MapS.data; MapS.data = 0; }
}
void MAPS::create() {
    MapS = game()->container()->data().mapS;

}
void MAPS::init() {
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, MapS.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", MapS.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (MapS.data) { delete[] MapS.data; MapS.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    MapS.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(MapS.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    MapS.rows = 0;
    MapS.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (MapS.data[i] == '\n') {
            if (MapS.rows == 0) {
                //�ŏ��̍s�̗�
                MapS.cols = cnt;
            }
            else if (MapS.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            MapS.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapS.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    MapS.dispCols = (int)width / MapS.chipSize + 1;//�\�����ׂ���
    //����dispRows�K�v

    MapS.worldWidth = (float)MapS.chipSize * (MapS.cols - 2);//���[���h�̉���
    MapS.endWorldX = MapS.worldWidth - width;//�\���ł���Ō�̍��W
    MapS.worldHeight = (float)MapS.chipSize * (MapS.rows);//���[���h�̏c��
    MapS.endWorldY = MapS.worldHeight - height;//�\���ł���Ō�̍��W
    MapS.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
    MapS.wy = 0.0f;//���ݕ\�����Ă��郏�[���h���W

}
void MAPS::update() {
    //�v���C���[���ł��Ă���@
    //���͉��ړ�������
    MapS.wy += 1;
    if (MapS.wy > MapS.endWorldY) {
        MapS.wy = MapS.endWorldY;
    }
    if (MapS.wx > MapS.endWorldX) {
        MapS.wx = MapS.endWorldX;
    }
}
void MAPS::draw() {
    int startCol = (int)MapS.wx / MapS.chipSize;//�\���J�n��
    int endCol = startCol + MapS.dispCols;//�\���I����
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapS.chipSize * c;
        for (int r = 0; r < MapS.rows; r++) {
            float wy = (float)MapS.chipSize * r;
            char charaId = MapS.data[r * MapS.cols + c];
            //�؂̊G���������閔�͉��Ƀ��N�g��u��
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - MapS.wx;
                float py = wy - MapS.wy;
                if (charaId == '1') image(MapS.blockImg, px, py);
                else if (charaId == '2')image(MapS.dublockImg, px, py);
                else if (charaId == '3')image(MapS.dnblockImg, px, py);
                else if (charaId == '4')image(MapS.wublockImg, px, py);
                else if (charaId == '5')image(MapS.wnblockImg, px, py);
                else if (charaId == '6')image(MapS.wiublockImg, px, py);
                else if (charaId == '7')image(MapS.widblockImg, px, py);
                else if (charaId == '8')image(MapS.strblockImg, px, py);
                else if (charaId == '9')image(MapS.tileImg, px, py);
                else if (charaId == '0')image(MapS.carpet1Img, px, py);
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                float px = wx - MapS.wx;
                float py = wy - MapS.wy;
                if (charaId == 't')image(MapS.wallTImg, px, py);
                else if (charaId == 'b')image(MapS.wallBImg, px, py);
                else if (charaId == 'r')image(MapS.wallRImg, px, py);


                else if (charaId == 'l')image(MapS.wallLImg, px, py);
                else if (charaId == 'w')image(MapS.wallWImg, px, py);
                else if (charaId == 'd')image(MapS.blockdImg, px, py);




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
