#include "CONTAINER.h"

void CONTAINER::load()
{
	setData();
	LoadGraphics();
}

void CONTAINER::setData()
{
	Data.title.pos.x = 500;
	Data.title.pos.y = 500;
	Data.title.slc = 700;
	Data.title.vy = 100;
	Data.title.w = 300;
	Data.title.h = 50;

	Data.map.fileName = "assets\\map1.txt";
	Data.map.chipSize = 50;
	Data.map.centerX = width / 2 - Data.map.chipSize / 2;
	Data.map.centerY = height / 2 - Data.map.chipSize / 2;


	//プレイヤー
	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 1;
	Data.playerChara.groupId = 0;//味方グループは0
	Data.playerChara.speed = 3.4f * 60;
	Data.playerChara.offsetLeft = 0;//仮
	Data.playerChara.offsetTop = 0;//仮
	Data.playerChara.offsetRight = 0;//仮
	Data.playerChara.offsetBottom = 0;//仮
	Data.player.rightAnimId = 0;
	Data.player.leftAnimId = 1;
	Data.player.upAnimId = 2;
	Data.player.downAnimId = 3;

	Data.charaMng.numPlayers = 1;

	//エネミー
	Data.enemyChara.charaId = MAP::ENEMY_ID;
	Data.enemyChara.hp = 99;
	Data.enemyChara.groupId = 0;//味方グループは0
	Data.enemyChara.speed = 3.4f * 60;
	Data.enemyChara.offsetLeft = 10.0f;//仮
	Data.enemyChara.offsetTop = 1.0f;//仮
	Data.enemyChara.offsetRight = 40.0f;//仮
	Data.enemyChara.offsetBottom = 49.0f;//仮
	Data.enemy.rightAnimId = 0;
	Data.enemy.leftAnimId = 1;
	Data.enemy.upAnimId = 2;
	Data.enemy.downAnimId = 3;


	Data.charaMng.numEnemies = 1;

	//ヒットポイント
	Data.hitpoint.px = 0;
	Data.hitpoint.py = 0;
	Data.hitpoint.offSetPx = 128;
	Data.hitpoint.numHitPointContainer = 3;



}

void CONTAINER::LoadGraphics()
{
	//ゲームオーバー
	Data.GameOver.img = loadImage("assets\\game_over.png");
	//ゲームクリア
	Data.GameClear.cimg = loadImage("assets\\CLAERback.png");
	//ブロック
	Data.map.blockImg = loadImage("assets\\carpet1.png");
	Data.map.dupblock = loadImage("assets\\doorUP.png");
	Data.map.ddnblock = loadImage("assets\\doorDN.png");
	Data.map.wallup = loadImage("assets\\wallUP.png");
	Data.map.walldn= loadImage("assets\\wallDN.png");
	Data.map.tile = loadImage("assets\\tile.png");
	Data.map.cp = loadImage("assets\\tukue.png");
	Data.map.stair = loadImage("assets\\isu.png");
	Data.map.blockd = loadImage("assets\\kuro.png");
	Data.map.blockr = loadImage("assets\\tana.png");
	Data.map.wallR = loadImage("assets\\wallR.png");
	Data.map.wallL = loadImage("assets\\wallL.png");
	Data.map.wallRL = loadImage("assets\\wallRL.png");
	Data.map.wallT = loadImage("assets\\wallT.png");
	Data.map.wallTR = loadImage("assets\\wallTR.png");
	Data.map.wallTL = loadImage("assets\\wallTL.png");

	Data.map.dRDN = loadImage("assets\\doorDNR.png");
	Data.map.dRUP = loadImage("assets\\doorUPR.png");

	//プレイヤー
	Data.player.Rimg = loadImage("assets\\playerR.png");
	Data.player.Limg = loadImage("assets\\playerL.png");
	Data.player.UPimg = loadImage("assets\\playerUP.png");
	Data.player.DNimg = loadImage("assets\\playerDN.png");


	//エネミー
	Data.enemy.rightImg = loadImage("assets\\reiR.png");
	Data.enemy.leftImg = loadImage("assets\\reiL.png");
	Data.enemy.upImg = loadImage("assets\\reiup.png");
	Data.enemy.downImg = loadImage("assets\\reidn.png");


	//タイトル
	Data.title.imgHan = loadImage("assets\\te.png");
	Data.title.imgS = loadImage("assets\\TITLES.png");
	Data.title.imgE = loadImage("assets\\TITLEE.png");
	Data.title.imgback = loadImage("assets\\titleback.png");

}

