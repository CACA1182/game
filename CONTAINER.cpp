#include "CONTAINER.h"
void CONTAINER::load() {
	setData();
	LoadGraphic();
}
void CONTAINER::setData() {
	Data.title.pos.x = 500;
	Data.title.pos.y = 500;
	Data.title.slc = 700;
	Data.title.vy = 100;
	Data.title.w = 300;
	Data.title.h = 50;


	Data.map.fileName = "assets\\map1.txt";
	Data.map2.fileName = "assets\\map2.txt";

	Data.map.chipSize = 50;
	Data.map2.chipSize = 50;

}
void CONTAINER::LoadGraphic() {
	Data.GameOver.img = loadImage("assets\\game_over.png");
	Data.title.imgHan = loadImage("assets\\te.png");

	Data.map.blockImg = loadImage("assets\\block.png");
	Data.map.dublockImg = loadImage("assets\\doorUP.png");
	Data.map.dnblockImg = loadImage("assets\\doorDN.png");
	Data.map.wublockImg = loadImage("assets\\wallUP.png");
	Data.map.wnblockImg = loadImage("assets\\wallDN.png");
	Data.map.wiublockImg = loadImage("assets\\windowUP.png");
	Data.map.widblockImg = loadImage("assets\\windowDN.png");
	Data.map.strblockImg = loadImage("assets\\stair.png");
	Data.map.carpet1Img = loadImage("assets\\carpet1.png");
	Data.map.tileImg = loadImage("assets\\tile.png");



	Data.map.wallTImg = loadImage("assets\\wallT.png");
	Data.map.wallBImg = loadImage("assets\\wallB.png");
	Data.map.wallRImg = loadImage("assets\\wallR.png");
	Data.map.wallLImg = loadImage("assets\\wallL.png");
	Data.map.wallWImg = loadImage("assets\\wallRL.png");
	Data.map.blockdImg = loadImage("assets\\blockd.png");


	Data.map2.blockImg = loadImage("assets\\block.png");
	Data.map2.dublockImg = loadImage("assets\\doorUP.png");
	Data.map2.dnblockImg = loadImage("assets\\doorDN.png");
	Data.map2.wublockImg = loadImage("assets\\wallUP.png");
	Data.map2.wnblockImg = loadImage("assets\\wallDN.png");
	Data.map2.wiublockImg = loadImage("assets\\windowUP.png");
	Data.map2.widblockImg = loadImage("assets\\windowDN.png");
	Data.map2.strblockImg = loadImage("assets\\stair.png");
	Data.map2.carpet1Img = loadImage("assets\\carpet1.png");
	Data.map2.tileImg = loadImage("assets\\tile.png");



	Data.map2.wallTImg = loadImage("assets\\wallT.png");
	Data.map2.wallBImg = loadImage("assets\\wallB.png");
	Data.map2.wallRImg = loadImage("assets\\wallR.png");
	Data.map2.wallLImg = loadImage("assets\\wallL.png");
	Data.map2.wallWImg = loadImage("assets\\wallRL.png");
	Data.map2.blockdImg = loadImage("assets\\blockd.png");





}
