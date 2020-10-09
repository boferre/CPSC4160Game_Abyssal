#include <string>

#include <SDL2/SDL.h> 

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
		} playCoord;
		
		// Level constants
		const int LEVEL_WIDTH = 2000;
		const int LEVEL_HEIGHT = 1000;
		
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

