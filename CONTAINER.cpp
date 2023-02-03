#include "CONTAINER.h"
void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	Data.title.pos.x = 500;
	Data.title.pos.y = 500;
	Data.title.slc = 700;
	Data.title.vy = 100;
	Data.title.w = 300;
	Data.title.h = 50;
	
}
void CONTAINER::loadGraphic() {
	Data.GameOver.img = loadImage("assets\\game_over.png");
	Data.title.imgHan = loadImage("assets\\te.png");
}
