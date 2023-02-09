#include"GAME.h"
#include"CONTAINER.h"
#include "MAPL.h"
MAPL::MAPL(class GAME* game) :
    GAME_OBJECT(game) {
}
MAPL::~MAPL() {
    if (MapL.data) { delete[] MapL.data; MapL.data = 0; }
}
void MAPL::create() {
    MapL = game()->container()->data().mapL;
}
void MAPL::init() {
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, MapL.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", MapL.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (MapL.data) { delete[] MapL.data; MapL.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    MapL.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(MapL.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    MapL.rows = 0;
    MapL.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (MapL.data[i] == '\n') {
            if (MapL.rows == 0) {
                //�ŏ��̍s�̗�
                MapL.cols = cnt;
            }
            else if (MapL.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            MapL.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapL.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    MapL.dispCols = (int)width / MapL.chipSize + 1;//�\�����ׂ���
    //����dispRows�K�v

    MapL.worldWidth = (float)MapL.chipSize * (MapL.cols - 2);//���[���h�̉���
    MapL.endWorldX = MapL.worldWidth - width;//�\���ł���Ō�̍��W
    MapL.worldHeight = (float)MapL.chipSize * (MapL.rows);//���[���h�̏c��
    MapL.endWorldY = MapL.worldHeight - height;//�\���ł���Ō�̍��W
    MapL.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
    MapL.wy = 0.0f;//���ݕ\�����Ă��郏�[���h���W

}
void MAPL::update() {
    //�v���C���[���ł��Ă���@
    //���͉��ړ�������
    MapL.wy += 1;
    if (MapL.wy > MapL.endWorldY) {
        MapL.wy = MapL.endWorldY;
    }
    if (MapL.wx > MapL.endWorldX) {
        MapL.wx = MapL.endWorldX;
    }
}
void MAPL::draw() {
    int startCol = (int)MapL.wx / MapL.chipSize;//�\���J�n��
    int endCol = startCol + MapL.dispCols;//�\���I����
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapL.chipSize * c;
        for (int r = 0; r < MapL.rows; r++) {
            float wy = (float)MapL.chipSize * r;
            char charaId = MapL.data[r * MapL.cols + c];
            //�؂̊G���������閔�͉��Ƀ��N�g��u��
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - MapL.wx;
                float py = wy - MapL.wy;
                if (charaId == '1') image(MapL.blockImg, px, py);
                else if (charaId == '2')image(MapL.dublockImg, px, py);
                else if (charaId == '3')image(MapL.dnblockImg, px, py);
                else if (charaId == '4')image(MapL.wublockImg, px, py);
                else if (charaId == '5')image(MapL.wnblockImg, px, py);
                else if (charaId == '6')image(MapL.wiublockImg, px, py);
                else if (charaId == '7')image(MapL.widblockImg, px, py);
                else if (charaId == '8')image(MapL.tatamiUPImg, px, py);
                else if (charaId == '9')image(MapL.tatamiDNImg, px, py);
                else if (charaId == '0')image(MapL.carpet1Img, px, py);
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                float px = wx - MapL.wx;
                float py = wy - MapL.wy;
                if (charaId == 't')image(MapL.wallTImg, px, py);
                else if (charaId == 'b')image(MapL.wallBImg, px, py);
                else if (charaId == 'r')image(MapL.wallRImg, px, py);


                else if (charaId == 'l')image(MapL.wallLImg, px, py);
                else if (charaId == 'w')image(MapL.wallWImg, px, py);
                else if (charaId == 'd')image(MapL.blockdImg, px, py);




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
