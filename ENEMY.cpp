

#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "ENEMY.h"
void ENEMY::create()
{
    Chara = game()->container()->data().enemyChara;
    Enemy = game()->container()->data().enemy;
}

void ENEMY::init()
{
    Chara.hp = 0;
    Chara.vx = 0.0f;
    Chara.vy = 0.0f;
    //Chara.wx = 0.0f;
    //Chara.wy = 0.0f;
    //Enemy_1.px = 0.0f;
    //Enemy_1.py = 0.0f;
    //Enemy_1.curWx = 0.0f;
    //Enemy_1.curWy = 0.0f;
    //Enemy_1.differenceX = 0.0f;
    //Enemy_1.differenceY = 0.0f;
    Enemy.dashFlag = false;
    Enemy.moveFlag = false;
}
void ENEMY::appear(float wx, float wy, float vx, float vy)
{
    Chara.hp = game()->container()->data().enemyChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Enemy.differenceX = wx;
    Enemy.differenceY = wy;
    Chara.animId = Enemy.leftAnimId;
}

void ENEMY::update()

{
    
    Move();
  
}


void ENEMY::Move()
{
    //左右上下移動
    //　移動ベクトルを決定
    homing();
 
    //  移動前に現在のChara.wxをPlayer.curWxにとっておく
    Enemy.curWx = Chara.wx;
    //  移動前に現在のChara.wyをPlayer.curWyにとっておく
    Enemy.curWy = Chara.wy;
    //  移動
   if (Chara.vx != 0.0f || Chara.vy != 0.0f) {//左右上下キー入力あり
        //とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
        //あとで、マップに食い込んでいたら、元のPlayer.curWxに戻す
        Chara.wx += Chara.vx;
        Chara.wy += Chara.vy;
   }
    //else {//左右上下キー入力がないとき
    //    Chara.animData.imgIdx = 0;
    //    Chara.animData.elapsedTime = -delta;
    //}ANIMclassができたらやる
}


void ENEMY::homing() {
        Chara.vx = 0.0f;
        Chara.vy = 0.0f;
       
            if (Enemy.px > game()->characterManager()->player()->px()) {
                Enemy.px += -Chara.speed * delta;
                    
                Chara.animId = Enemy.leftAnimId;
            }
            else
            {
                Enemy.px += Chara.speed * delta;
                Chara.animId = Enemy.rightAnimId;
            }
        
       
            if (Enemy.py > game()->characterManager()->player()->py()) {
                Enemy.py += -Chara.speed * delta;
                Chara.animId = Enemy.upAnimId;
            }

            else
            {
                Enemy.py += Chara.speed * delta;
                Chara.animId = Enemy.downAnimId;
            }
        
    
}




void ENEMY::draw()
{
    
    Enemy.px = Chara.wx - game()->map()->wx();
    Enemy.py = Chara.wy - game()->map()->wy();
    if (Chara.animId == Enemy.rightAnimId) {
        image(Enemy.rightImg, Enemy.px, Enemy.py);
    }
    else if (Chara.animId == Enemy.leftAnimId) {
        image(Enemy.leftImg, Enemy.px, Enemy.py);
    }
    else if (Chara.animId == Enemy.upAnimId) {
        image(Enemy.upImg, Enemy.px, Enemy.py);
    }
    else if (Chara.animId == Enemy.downAnimId) {
        image(Enemy.downImg, Enemy.px, Enemy.py);
    }
}

void ENEMY::damage()
{
    if (Chara.hp > 0) {
        Chara.hp--;
        if (Chara.hp == 0) {
            State = STATE::DIED;
        }
    }
}

bool ENEMY::died()
{
    if (State == STATE::DIED) {
        return true;
    }
    return false;
}

bool ENEMY::survived()
{
    return State == STATE::SURVIVED;
}



