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
    //ファイルを開く
    FILE* fp;
    fopen_s(&fp, MapL.fileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", MapL.fileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (MapL.data) { delete[] MapL.data; MapL.data = 0; }
    //サイズ分のdata配列を用意する
    MapL.data = new char[fileSize];
    //データを読み込む
    fread(MapL.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    MapL.rows = 0;
    MapL.cols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (MapL.data[i] == '\n') {
            if (MapL.rows == 0) {
                //最初の行の列数
                MapL.cols = cnt;
            }
            else if (MapL.cols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            MapL.rows++;
            cnt = 0;
        }
    }
    if (fileSize % MapL.cols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    MapL.dispCols = (int)width / MapL.chipSize + 1;//表示すべき列数
    //多分dispRows必要

    MapL.worldWidth = (float)MapL.chipSize * (MapL.cols - 2);//ワールドの横幅
    MapL.endWorldX = MapL.worldWidth - width;//表示できる最後の座標
    MapL.worldHeight = (float)MapL.chipSize * (MapL.rows);//ワールドの縦幅
    MapL.endWorldY = MapL.worldHeight - height;//表示できる最後の座標
    MapL.wx = 0.0f;//現在表示しているワールド座標
    MapL.wy = 0.0f;//現在表示しているワールド座標

}
void MAPL::update() {
    //プレイヤーができてから　
    //又は仮移動をする
    MapL.wy += 1;
    if (MapL.wy > MapL.endWorldY) {
        MapL.wy = MapL.endWorldY;
    }
    if (MapL.wx > MapL.endWorldX) {
        MapL.wx = MapL.endWorldX;
    }
}
void MAPL::draw() {
    int startCol = (int)MapL.wx / MapL.chipSize;//表示開始列
    int endCol = startCol + MapL.dispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)MapL.chipSize * c;
        for (int r = 0; r < MapL.rows; r++) {
            float wy = (float)MapL.chipSize * r;
            char charaId = MapL.data[r * MapL.cols + c];
            //木の絵がきたらやる又は仮にレクトを置く
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
