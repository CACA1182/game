#include"GAME.h"
#include"CONTAINER.h"
#include "MAP.h"
MAP2::MAP2(class GAME* game) :
    GAME_OBJECT(game) {
}
MAP2::~MAP2() {
    if (Map2.data) { delete[] Map2.data; Map2.data = 0; }
}
void MAP2::create() {
    Map2 = game()->container()->data().map2;
}
void MAP2::init() {
    //ファイルを開く
    FILE* fp;
    fopen_s(&fp, Map2.fileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", Map2.fileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (Map2.data) { delete[] Map2.data; Map2.data = 0; }
    //サイズ分のdata配列を用意する
    Map2.data = new char[fileSize];
    //データを読み込む
    fread(Map2.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    Map2.rows = 0;
    Map2.cols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (Map2.data[i] == '\n') {
            if (Map2.rows == 0) {
                //最初の行の列数
                Map2.cols = cnt;
            }
            else if (Map2.cols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            Map2.rows++;
            cnt = 0;
        }
    }
    if (fileSize % Map2.cols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    Map2.dispCols = (int)width / Map2.chipSize + 1;//表示すべき列数
    //多分dispRows必要

    Map2.worldWidth = (float)Map2.chipSize * (Map2.cols - 2);//ワールドの横幅
    Map2.endWorldX = Map2.worldWidth - width;//表示できる最後の座標
    Map2.worldHeight = (float)Map2.chipSize * (Map2.rows);//ワールドの縦幅
    Map2.endWorldY = Map2.worldHeight - height;//表示できる最後の座標
    Map2.wx = 0.0f;//現在表示しているワールド座標
    Map2.wy = 0.0f;//現在表示しているワールド座標

}
void MAP2::update() {
    //プレイヤーができてから　
    //又は仮移動をする
    Map2.wy += 1;
    if (Map2.wy > Map2.endWorldY) {
        Map2.wy = Map2.endWorldY;
    }
    if (Map2.wx > Map2.endWorldX) {
        Map2.wx = Map2.endWorldX;
    }
}
void MAP2::draw() {
    int startCol = (int)Map2.wx / Map2.chipSize;//表示開始列
    int endCol = startCol + Map2.dispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)Map2.chipSize * c;
        for (int r = 0; r < Map2.rows; r++) {
            float wy = (float)Map2.chipSize * r;
            char charaId = Map2.data[r * Map2.cols + c];
            //木の絵がきたらやる又は仮にレクトを置く
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - Map2.wx;
                float py = wy - Map2.wy;
                if (charaId == '1') image(Map2.blockImg, px, py);
                else if (charaId == '2')image(Map2.dublockImg, px, py);
                else if (charaId == '3')image(Map2.dnblockImg, px, py);
                else if (charaId == '4')image(Map2.wublockImg, px, py);
                else if (charaId == '5')image(Map2.wnblockImg, px, py);
                else if (charaId == '6')image(Map2.wiublockImg, px, py);
                else if (charaId == '7')image(Map2.widblockImg, px, py);
                else if (charaId == '8')image(Map2.strblockImg, px, py);
                else if (charaId == '9')image(Map2.tileImg, px, py);
                else if (charaId == '0')image(Map2.carpet1Img, px, py);
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                float px = wx - Map2.wx;
                float py = wy - Map2.wy;
                if (charaId == 't')image(Map2.wallTImg, px, py);
                else if (charaId == 'b')image(Map2.wallBImg, px, py);
                else if (charaId == 'r')image(Map2.wallRImg, px, py);


                else if (charaId == 'l')image(Map2.wallLImg, px, py);
                else if (charaId == 'w')image(Map2.wallWImg, px, py);
                else if (charaId == 'd')image(Map2.blockdImg, px, py);




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
