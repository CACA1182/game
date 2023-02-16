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

	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 3;
	Data.playerChara.groupId = 0;//味方グループは0
	Data.playerChara.speed = 3.4f * 60;
	Data.playerChara.offsetLeft = 10.0f;//仮
	Data.playerChara.offsetTop = 1.0f;//仮
	Data.playerChara.offsetRight = 40.0f;//仮
	Data.playerChara.offsetBottom = 49.0f;//仮
	Data.player.rightAnimId = 0;
	Data.player.leftAnimId = 1;
	Data.player.upAnimId = 2;
	Data.player.downAnimId = 3;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numPlayerBullets = 0;


}

void CONTAINER::LoadGraphics()
{
	//ゲームオーバー
	Data.GameOver.img = loadImage("assets\\game_over.png");
	//ブロック
	Data.map.blockImg = loadImage("assets\\block.png");
	Data.map.dupblock = loadImage("assets\\doorUP.png");
	Data.map.ddnblock = loadImage("assets\\doorDN.png");
	Data.map.wallup = loadImage("assets\\wallUP.png");
	Data.map.walldn= loadImage("assets\\wallDN.png");
	Data.map.tile = loadImage("assets\\tile.png");
	Data.map.cp = loadImage("assets\\carpet1.png");
	Data.map.stair = loadImage("assets\\stair.png");
	Data.map.blockd = loadImage("assets\\blockd.png");
	Data.map.blockr = loadImage("assets\\blockr.png");
	Data.map.wallR = loadImage("assets\\wallR.png");
	Data.map.wallL = loadImage("assets\\wallL.png");
	Data.map.wallRL = loadImage("assets\\wallRL.png");
	Data.map.wallT = loadImage("assets\\wallT.png");
	Data.map.wallTR = loadImage("assets\\wallTR.png");
	Data.map.wallTL = loadImage("assets\\wallTL.png");






	//タイトル
	Data.title.imgHan = loadImage("assets\\te.png");
	Data.title.imgS = loadImage("assets\\TITLES.png");
	Data.title.imgE = loadImage("assets\\TITLEE.png");
	Data.title.imgback = loadImage("assets\\titleback.png");

}

