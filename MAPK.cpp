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
    //ファイルを開く
    FILE* fp;
    fopen_s(&fp, MapK.fileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", MapK.fileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (MapK.data) { delete[] MapK.data; MapK.data = 0; }
    //サイズ分のdata配列を用意する
    MapK.data = new char[fileSize];
    //データを読み込む
    fread(MapK.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    MapK.rows = 0;
    MapK.cols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (MapK.data[i] == '\n') {
            if (MapK.rows == 0) {
                //最初の行の列数
                MapK.cols = cnt;
            }
            else if (MapK.cols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            MapK.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapK.cols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    MapK.dispCols = (int)width / MapK.chipSize + 1;//表示すべき列数
    //多分dispRows必要

    MapK.worldWidth = (float)MapK.chipSize * (MapK.cols - 2);//ワールドの横幅
    MapK.endWorldX = MapK.worldWidth - width;//表示できる最後の座標
    MapK.worldHeight = (float)MapK.chipSize * (MapK.rows);//ワールドの縦幅
    MapK.endWorldY = MapK.worldHeight - height;//表示できる最後の座標
    MapK.wx = 0.0f;//現在表示しているワールド座標
    MapK.wy = 0.0f;//現在表示しているワールド座標

}
void MAPK::update() {
    //プレイヤーができてから　
    //又は仮移動をする
    MapK.wy += 1;
    if (MapK.wy > MapK.endWorldY) {
        MapK.wy = MapK.endWorldY;
    }
    if (MapK.wx > MapK.endWorldX) {
        MapK.wx = MapK.endWorldX;
    }
}
void MAPK::draw() {
    int startCol = (int)MapK.wx / MapK.chipSize;//表示開始列
    int endCol = startCol + MapK.dispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapK.chipSize * c;
        for (int r = 0; r < MapK.rows; r++) {
            float wy = (float)MapK.chipSize * r;
            char charaId = MapK.data[r * MapK.cols + c];
            //木の絵がきたらやる又は仮にレクトを置く
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
