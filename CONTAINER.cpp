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
	Data.mapL.fileName = "assets\\mapL.txt";
	Data.mapK.fileName = "assets\\mapK.txt";
	Data.mapH.fileName = "assets\\mapH.txt";
	Data.mapB.fileName = "assets\\mapB.txt";
	Data.mapS.fileName = "assets\\mapS.txt";





	Data.map.chipSize = 50;
	Data.map2.chipSize = 50;
	Data.mapL.chipSize = 50;
	Data.mapK.chipSize = 50;
	Data.mapH.chipSize = 50;
	Data.mapB.chipSize = 50;
	Data.mapS.chipSize = 50;





}
void CONTAINER::LoadGraphic() {
	//ÉQÅ[ÉÄÉIÅ[ÉoÅ[
	Data.GameOver.img = loadImage("assets\\game_over.png");

	//É^ÉCÉgÉã
	Data.title.imgHan = loadImage("assets\\te.png");
	Data.title.imgS = loadImage("assets\\TITLES.png");
	Data.title.imgE = loadImage("assets\\TITLEE.png");



	//àÍäKòLâ∫
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

	//ìÒäKòLâ∫
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
	//ÉäÉrÉìÉO
	Data.mapL.blockImg = loadImage("assets\\block.png");
	Data.mapL.dublockImg = loadImage("assets\\doorUP.png");
	Data.mapL.dnblockImg = loadImage("assets\\doorDN.png");
	Data.mapL.wublockImg = loadImage("assets\\husumaUP.png");
	Data.mapL.wnblockImg = loadImage("assets\\husumaDN.png");
	Data.mapL.wiublockImg = loadImage("assets\\windowUP.png");
	Data.mapL.widblockImg = loadImage("assets\\windowDN.png");
	Data.mapL.tatamiUPImg = loadImage("assets\\tatamiUP.png");
	Data.mapL.carpet1Img = loadImage("assets\\carpet1.png");
	Data.mapL.tatamiDNImg = loadImage("assets\\tatamiDN.png");



	Data.mapL.wallTImg = loadImage("assets\\wallT.png");
	Data.mapL.wallBImg = loadImage("assets\\wallB.png");
	Data.mapL.wallRImg = loadImage("assets\\wallR.png");
	Data.mapL.wallLImg = loadImage("assets\\wallL.png");
	Data.mapL.wallWImg = loadImage("assets\\wallRL.png");
	Data.mapL.blockdImg = loadImage("assets\\blockd.png");

	//ÉLÉbÉ`Éì
	Data.mapK.blockImg = loadImage("assets\\block.png");
	Data.mapK.dublockImg = loadImage("assets\\doorUP.png");
	Data.mapK.dnblockImg = loadImage("assets\\doorDN.png");
	Data.mapK.wublockImg = loadImage("assets\\wallUP.png");
	Data.mapK.wnblockImg = loadImage("assets\\wallDN.png");
	Data.mapK.wiublockImg = loadImage("assets\\windowUP.png");
	Data.mapK.widblockImg = loadImage("assets\\windowDN.png");
	Data.mapK.strblockImg = loadImage("assets\\stair.png");
	Data.mapK.carpet1Img = loadImage("assets\\carpet1.png");
	Data.mapK.tileImg = loadImage("assets\\tile.png");



	Data.mapK.wallTImg = loadImage("assets\\wallT.png");
	Data.mapK.wallBImg = loadImage("assets\\wallB.png");
	Data.mapK.wallRImg = loadImage("assets\\wallR.png");
	Data.mapK.wallLImg = loadImage("assets\\wallL.png");
	Data.mapK.wallWImg = loadImage("assets\\wallRL.png");
	Data.mapK.blockdImg = loadImage("assets\\blockd.png");


	//ïóòC
	Data.mapH.blockImg = loadImage("assets\\tile.png");
	Data.mapH.dublockImg = loadImage("assets\\doorUP.png");
	Data.mapH.dnblockImg = loadImage("assets\\doorDN.png");
	Data.mapH.wublockImg = loadImage("assets\\wallUP.png");
	Data.mapH.wnblockImg = loadImage("assets\\wallDN.png");
	Data.mapH.wiublockImg = loadImage("assets\\windowUP.png");
	Data.mapH.widblockImg = loadImage("assets\\windowDN.png");
	Data.mapH.strblockImg = loadImage("assets\\stair.png");
	Data.mapH.carpet1Img = loadImage("assets\\carpet1.png");
	Data.mapH.tileImg = loadImage("assets\\tile.png");



	Data.mapH.wallTImg = loadImage("assets\\wallT.png");
	Data.mapH.wallBImg = loadImage("assets\\wallB.png");
	Data.mapH.wallRImg = loadImage("assets\\wallR.png");
	Data.mapH.wallLImg = loadImage("assets\\wallL.png");
	Data.mapH.wallWImg = loadImage("assets\\wallRL.png");
	Data.mapH.blockdImg = loadImage("assets\\blockd.png");
	


	//êQé∫
	Data.mapB.blockImg = loadImage("assets\\block.png");
	Data.mapB.dublockImg = loadImage("assets\\doorUP.png");
	Data.mapB.dnblockImg = loadImage("assets\\doorDN.png");
	Data.mapB.wublockImg = loadImage("assets\\wallUP.png");
	Data.mapB.wnblockImg = loadImage("assets\\wallDN.png");
	Data.mapB.wiublockImg = loadImage("assets\\windowUP.png");
	Data.mapB.widblockImg = loadImage("assets\\windowDN.png");
	Data.mapB.strblockImg = loadImage("assets\\stair.png");
	Data.mapB.carpet1Img = loadImage("assets\\carpet1.png");
	Data.mapB.tileImg = loadImage("assets\\tile.png");



	Data.mapB.wallTImg = loadImage("assets\\wallT.png");
	Data.mapB.wallBImg = loadImage("assets\\wallB.png");
	Data.mapB.wallRImg = loadImage("assets\\wallR.png");
	Data.mapB.wallLImg = loadImage("assets\\wallL.png");
	Data.mapB.wallWImg = loadImage("assets\\wallRL.png");
	Data.mapB.blockdImg = loadImage("assets\\blockd.png");

	//èëç÷
	Data.mapS.blockImg = loadImage("assets\\block.png");
	Data.mapS.dublockImg = loadImage("assets\\doorUP.png");
	Data.mapS.dnblockImg = loadImage("assets\\doorDN.png");
	Data.mapS.wublockImg = loadImage("assets\\wallUP.png");
	Data.mapS.wnblockImg = loadImage("assets\\wallDN.png");
	Data.mapS.wiublockImg = loadImage("assets\\windowUP.png");
	Data.mapS.widblockImg = loadImage("assets\\windowDN.png");
	Data.mapS.strblockImg = loadImage("assets\\stair.png");
	Data.mapS.carpet1Img = loadImage("assets\\carpet1.png");
	Data.mapS.tileImg = loadImage("assets\\tile.png");



	Data.mapS.wallTImg = loadImage("assets\\wallT.png");
	Data.mapS.wallBImg = loadImage("assets\\wallB.png");
	Data.mapS.wallRImg = loadImage("assets\\wallR.png");
	Data.mapS.wallLImg = loadImage("assets\\wallL.png");
	Data.mapS.wallWImg = loadImage("assets\\wallRL.png");
	Data.mapS.blockdImg = loadImage("assets\\blockd.png");

}
