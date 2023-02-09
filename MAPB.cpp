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
    //ファイルを開く
    FILE* fp;
    fopen_s(&fp, MapB.fileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", MapB.fileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (MapB.data) { delete[] MapB.data; MapB.data = 0; }
    //サイズ分のdata配列を用意する
    MapB.data = new char[fileSize];
    //データを読み込む
    fread(MapB.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    MapB.rows = 0;
    MapB.cols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (MapB.data[i] == '\n') {
            if (MapB.rows == 0) {
                //最初の行の列数
                MapB.cols = cnt;
            }
            else if (MapB.cols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            MapB.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapB.cols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    MapB.dispCols = (int)width / MapB.chipSize + 1;//表示すべき列数
    //多分dispRows必要

    MapB.worldWidth = (float)MapB.chipSize * (MapB.cols - 2);//ワールドの横幅
    MapB.endWorldX = MapB.worldWidth - width;//表示できる最後の座標
    MapB.worldHeight = (float)MapB.chipSize * (MapB.rows);//ワールドの縦幅
    MapB.endWorldY = MapB.worldHeight - height;//表示できる最後の座標
    MapB.wx = 0.0f;//現在表示しているワールド座標
    MapB.wy = 0.0f;//現在表示しているワールド座標

}
void MAPB::update() {
    //プレイヤーができてから　
    //又は仮移動をする
    MapB.wy += 1;
    if (MapB.wy > MapB.endWorldY) {
        MapB.wy = MapB.endWorldY;
    }
    if (MapB.wx > MapB.endWorldX) {
        MapB.wx = MapB.endWorldX;
    }
}
void MAPB::draw() {
    int startCol = (int)MapB.wx / MapB.chipSize;//表示開始列
    int endCol = startCol + MapB.dispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapB.chipSize * c;
        for (int r = 0; r < MapB.rows; r++) {
            float wy = (float)MapB.chipSize * r;
            char charaId = MapB.data[r * MapB.cols + c];
            //木の絵がきたらやる又は仮にレクトを置く
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
