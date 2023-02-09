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
    //ファイルを開く
    FILE* fp;
    fopen_s(&fp, MapH.fileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", MapH.fileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (MapH.data) { delete[] MapH.data; MapH.data = 0; }
    //サイズ分のdata配列を用意する
    MapH.data = new char[fileSize];
    //データを読み込む
    fread(MapH.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    MapH.rows = 0;
    MapH.cols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (MapH.data[i] == '\n') {
            if (MapH.rows == 0) {
                //最初の行の列数
                MapH.cols = cnt;
            }
            else if (MapH.cols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            MapH.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapH.cols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    MapH.dispCols = (int)width / MapH.chipSize + 1;//表示すべき列数
    //多分dispRows必要

    MapH.worldWidth = (float)MapH.chipSize * (MapH.cols - 2);//ワールドの横幅
    MapH.endWorldX = MapH.worldWidth - width;//表示できる最後の座標
    MapH.worldHeight = (float)MapH.chipSize * (MapH.rows);//ワールドの縦幅
    MapH.endWorldY = MapH.worldHeight - height;//表示できる最後の座標
    MapH.wx = 0.0f;//現在表示しているワールド座標
    MapH.wy = 0.0f;//現在表示しているワールド座標

}
void MAPH::update() {
    //プレイヤーができてから　
    //又は仮移動をする
    MapH.wy += 1;
    if (MapH.wy > MapH.endWorldY) {
        MapH.wy = MapH.endWorldY;
    }
    if (MapH.wx > MapH.endWorldX) {
        MapH.wx = MapH.endWorldX;
    }
}
void MAPH::draw() {
    int startCol = (int)MapH.wx / MapH.chipSize;//表示開始列
    int endCol = startCol + MapH.dispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapH.chipSize * c;
        for (int r = 0; r < MapH.rows; r++) {
            float wy = (float)MapH.chipSize * r;
            char charaId = MapH.data[r * MapH.cols + c];
            //木の絵がきたらやる又は仮にレクトを置く
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
