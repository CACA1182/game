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
    //ファイルを開く
    FILE* fp;
    fopen_s(&fp, MapS.fileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", MapS.fileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (MapS.data) { delete[] MapS.data; MapS.data = 0; }
    //サイズ分のdata配列を用意する
    MapS.data = new char[fileSize];
    //データを読み込む
    fread(MapS.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    MapS.rows = 0;
    MapS.cols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (MapS.data[i] == '\n') {
            if (MapS.rows == 0) {
                //最初の行の列数
                MapS.cols = cnt;
            }
            else if (MapS.cols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            MapS.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapS.cols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    MapS.dispCols = (int)width / MapS.chipSize + 1;//表示すべき列数
    //多分dispRows必要

    MapS.worldWidth = (float)MapS.chipSize * (MapS.cols - 2);//ワールドの横幅
    MapS.endWorldX = MapS.worldWidth - width;//表示できる最後の座標
    MapS.worldHeight = (float)MapS.chipSize * (MapS.rows);//ワールドの縦幅
    MapS.endWorldY = MapS.worldHeight - height;//表示できる最後の座標
    MapS.wx = 0.0f;//現在表示しているワールド座標
    MapS.wy = 0.0f;//現在表示しているワールド座標

}
void MAPS::update() {
    //プレイヤーができてから　
    //又は仮移動をする
    MapS.wy += 1;
    if (MapS.wy > MapS.endWorldY) {
        MapS.wy = MapS.endWorldY;
    }
    if (MapS.wx > MapS.endWorldX) {
        MapS.wx = MapS.endWorldX;
    }
}
void MAPS::draw() {
    int startCol = (int)MapS.wx / MapS.chipSize;//表示開始列
    int endCol = startCol + MapS.dispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapS.chipSize * c;
        for (int r = 0; r < MapS.rows; r++) {
            float wy = (float)MapS.chipSize * r;
            char charaId = MapS.data[r * MapS.cols + c];
            //木の絵がきたらやる又は仮にレクトを置く
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
