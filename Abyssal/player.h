#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#ifndef player_H
#define player_H

class Player {
	private:
		int hullstrength;
		int shipSpeed = 1;
		
		struct position {
			int x = 0;
			int y = 100;
		} playCoord;
		
		
		
	public:
		int getSpeed() {return shipSpeed;};
		void setSpeed(int val) {shipSpeed = val;};
		
		int getPosX() {return playCoord.x;};
		void setPosX(int val) { playCoord.x = val;};
		
		int getPosY() {return playCoord.y;};
		void setPosY(int val) {playCoord.y = val;};
		
		bool playerController();
};

#endif

