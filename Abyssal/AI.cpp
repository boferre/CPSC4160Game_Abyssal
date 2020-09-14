#include "AI.h"

void AI::createship(int AIID, int x, int y, int w, int h, int a, char* ship) {
	test[AIID].x = x;
	test[AIID].y = y;
	test[AIID].w = w;
	test[AIID].h = h;
	test[AIID].angle = a;
	test[AIID].shipfile = ship;
}


void AI::setSpeed(int val, int AIID) {
	
}


void AI::setPosX(int val, int AIID) {
	
}
		

void AI::setPosY(int val, int AIID) { 
	
}


void AI::AIControl(int AIID, char dir) {
	switch(dir) {
		case 'n':
			test[AIID].y--;
		break;
		case 's':
			test[AIID].y++;
		break;
		case 'e':
			test[AIID].x++;
		break;
		case 'w':
			test[AIID].x--;
		break;
	}
}
