#include <string>
#include <iostream>
#include <string.h>

#include <SDL.h> 

#ifndef player_H
#define player_H

class Player {
	private:
		int hullstrength;
		
		//movement
		int maxSpeed = 3;
		int initialSpeed = 0;
		int accSpeed = 1;
		
		
		// Location
		struct position {
			int x = 0;
			int y = 100;
			int angle = 0;
			int h = 25;
			int w = 25;
			char* shipFile = "./Assets/Ships/Leisure/Cutter.png";
			
			int animState;
			int imageX;
			int imageY;
		} playCoord;
		
		// Level constants
		const int LEVEL_WIDTH = 852;
		const int LEVEL_HEIGHT = 480;
		
	public:
	// Movement functions (velocity and orientation based)
		
		int getPosX() {return playCoord.x;};
		void setPosX(int val) { playCoord.x = val;};
		
		int getPosY() {return playCoord.y;};
		void setPosY(int val) {playCoord.y = val;};
		
		int getAngle() {return playCoord.angle;};
		void setAngle(int val) {playCoord.angle = val;};
		
		int getHeight() {return playCoord.h;};
		int getWidth() {return playCoord.w;};
		char* getShipFile() {return playCoord.shipFile;};
		
	// Control functions
		bool playerController();
};

#endif

