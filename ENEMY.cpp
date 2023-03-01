

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
    Enemy.ex = 0;
        //Chara.wx - game()->map()->wx();
    Enemy.ey = 0;
        //Chara.wy - game()->map()->wy();
  
}
void ENEMY::appear(float ewx, float ewy, float vx, float vy)
{
    Chara.hp = game()->container()->data().enemyChara.hp;
    Chara.wx = ewx;
    Chara.wy = ewy;
   // Enemy.differenceX = wx;
   // Enemy.differenceY = wy;
  //  Chara.animId = Enemy.leftAnimId;
}

void ENEMY::update()

{
    
    homing();
  
}




void ENEMY::homing() {
     //   Chara.vx = 0.0f;
       // Chara.vy = 0.0f;
       
            if (Enemy.ey > game()->characterManager()->player()->py()) {
                Chara.animId = Enemy.upAnimId;
                Enemy.ey -= Chara.speed * delta;

            }
            
            else 
            {
                Chara.animId = Enemy.downAnimId;
                Enemy.ey += Chara.speed * delta;

            }
            

            if (Enemy.ex > game()->characterManager()->player()->px()) {
                Chara.animId = Enemy.leftAnimId;
                Enemy.ex -= Chara.speed * delta;

            }
            if (Enemy.ex > game()->characterManager()->player()->px())
            {
                Chara.animId = Enemy.rightAnimId;
                Enemy.ex += Chara.speed * delta;

            }
        
       
        
    
}




void ENEMY::draw()
{
    
  
    if (Chara.animId == Enemy.rightAnimId) {

        image(Enemy.rightImg, Enemy.ex, Enemy.ey);
    }
    else if (Chara.animId == Enemy.leftAnimId) {

        image(Enemy.leftImg, Enemy.ex, Enemy.ey);
    }
    else if (Chara.animId == Enemy.upAnimId) {

        image(Enemy.upImg, Enemy.ex, Enemy.ey);
    }
    else if (Chara.animId == Enemy.downAnimId) {

        image(Enemy.downImg, Enemy.ex, Enemy.ey);
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



