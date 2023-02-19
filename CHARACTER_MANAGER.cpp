#include"GAME.h"
#include"CONTAINER.h"

#include"PLAYER.h"
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
    int i, j = 0;
    for (i = 0; i < CharaMng.numPlayers; i++)       Characters[j++] = Player;

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
    // charaId�Ŏw�肳�ꂽ�L�������o��������
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
    //�L�����ƃL�����̓����蔻��---------------------------------------------------
    for (int i = 0; i < Total - 1; i++) {
        if (Characters[i]->hp() == 0) {
            continue;// ��������i++�ɖ߂�
        }
        for (int j = i + 1; j < Total; j++) {
            if (Characters[j]->hp() == 0) {
                continue;// ��������j++�ɖ߂�
            }
            //���Ԃǂ����͓����蔻�肵�Ȃ�
            if (Characters[i]->groupId() == Characters[j]->groupId()) {
                continue;// ��������j++�ɖ߂�
            }
            //�����蔻��
            if (Characters[i]->wLeft() < Characters[j]->wRight() &&
                Characters[j]->wLeft() < Characters[i]->wRight() &&
                Characters[i]->wTop() < Characters[j]->wBottom() &&
                Characters[j]->wTop() < Characters[i]->wBottom()) {
                //��������
                if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 1) {
                    //�v���C���[�ƓG��������ꍇ�v���C���[�����_���[�W��������悤�ȕ���
                    Characters[i]->damage();
                }
                else if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 4) {
                    //�v���C���[�ƃA�C�e����������ꍇ�A�C�e�������_���[�W��������悤�ȕ���
                    Characters[j]->damage();
                }
                else if (Characters[i]->groupId() == 1 && Characters[j]->groupId() == 4) {
                    //�G�ƃA�C�e���͓�����Ȃ�����
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
