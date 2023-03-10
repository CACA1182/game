#include"GAME.h"
#include"CONTAINER.h"

#include"PLAYER.h"
#include"ENEMY.h"
#include"CHARACTER.h"
#include "CHARACTER_MANAGER.h"

CHARACTER_MANAGER::CHARACTER_MANAGER(GAME* game) :
    GAME_OBJECT(game)
{
}

CHARACTER_MANAGER::~CHARACTER_MANAGER()
{
    for (int i = 0; i < Total; i++) {
        delete Characters[i];
    }
    delete[] Characters;
}

void CHARACTER_MANAGER::create()
{
    CharaMng = game()->container()->data().charaMng;

    Total = 0;
    Total += CharaMng.numEnemies;

    Total += CharaMng.numPlayers;

    Characters = new CHARACTER * [Total];

    Player = new PLAYER(game());
    int  i,j = 0;
    for (i = 0; i < CharaMng.numPlayers; i++)       Characters[j++] = Player;

    Enemy = new ENEMY(game());

    for (i = 0; i < CharaMng.numEnemies; i++)       Characters[j++] = Enemy;

    for (int i = 0; i < Total; i++) {
        Characters[i]->create();
    }
  
}

void CHARACTER_MANAGER::init()
{
    for (int i = 0; i < Total; i++) {
        Characters[i]->init();
    }
}

void CHARACTER_MANAGER::appear(char charaId, float wx, float wy, float vx, float vy)
{
    // charaIdで指定されたキャラを出現させる
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->charaId() == charaId) {
            if (Characters[i]->hp() <= 0) {
                Characters[i]->appear(wx, wy, vx, vy);
                break;
            }
        }
    }
}

void CHARACTER_MANAGER::update()
{
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->update();
        }
    }
    //キャラとキャラの当たり判定---------------------------------------------------
    for (int i = 0; i < Total - 1; i++) {
        if (Characters[i]->hp() == 0) {
            continue;// ←ここでi++に戻る
        }
        for (int j = i + 1; j < Total; j++) {
            if (Characters[j]->hp() == 0) {
                continue;// ←ここでj++に戻る
            }
            //仲間どうしは当たり判定しない
            if (Characters[i]->groupId() == Characters[j]->groupId()) {
                continue;// ←ここでj++に戻る
            }
            //当たり判定
            if (Characters[i]->wLeft() < Characters[j]->wRight() &&
                Characters[j]->wLeft() < Characters[i]->wRight() &&
                Characters[i]->wTop() < Characters[j]->wBottom() &&
                Characters[j]->wTop() < Characters[i]->wBottom()) {
                //当たった
                if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 1) {
                    //プレイヤーと敵が当たる場合プレイヤーだけダメージが当たるような分岐
                    Characters[i]->damage();
                }
                else if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 4) {
                    //プレイヤーとアイテムが当たる場合アイテムだけダメージが当たるような分岐
                    Characters[j]->damage();
                }
                else if (Characters[i]->groupId() == 1 && Characters[j]->groupId() == 4) {
                    //敵とアイテムは当たらない判定
                }
                Characters[i]->damage();
                Characters[j]->damage();
            }
        }
    }
}

void CHARACTER_MANAGER::draw()
{
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->draw();
        }
    }
}
