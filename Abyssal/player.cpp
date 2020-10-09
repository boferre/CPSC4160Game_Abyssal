#include <iostream>
#include <string.h>

#include <SDL2/SDL.h> 

#include "player.h"

bool Player::playerController() {
	SDL_Event handler;	
	
	char* animState = "IDLE";
	
	// Tank based controls
	while(SDL_PollEvent(&handler) != 0) {
		if (handler.type == SDL_QUIT) {
			std::cout << "Quiting" << std::endl;
			return false;
		} else if (handler.type == SDL_KEYDOWN) {
			switch(handler.key.keysym.sym ) {
				
				// Accelerate 
				case SDLK_UP:
					if (initialSpeed <= maxSpeed)
						initialSpeed++;
				break;
				
				// Deccelerate
				case SDLK_DOWN:
					if (initialSpeed > -(maxSpeed))
						initialSpeed--;
				break;
				
				// turn left
				case SDLK_LEFT:
					if (playCoord.angle <= 0) {
						playCoord.angle = 359;
					} else {
						playCoord.angle--;
					}
				break;
				
				// Turn right
				case SDLK_RIGHT:
					if (playCoord.angle >= 360) {
						playCoord.angle = 0;
					} else {
							playCoord.angle ++;
					}
				break;
			}
		}
	}
	
	// Position calculations 
	if (initialSpeed != 0) {
		if (playCoord.angle >= 20 && playCoord.angle <= 70) {
			playCoord.x += initialSpeed;
			playCoord.y += initialSpeed;
		} else if (playCoord.angle >= 110 && playCoord.angle <= 160) {
			playCoord.x -= initialSpeed;
			playCoord.y += initialSpeed;
		} else if (playCoord.angle <= 19 || playCoord.angle >= 340) {
			playCoord.x += initialSpeed;
		}
		//ADD MORE CASES
	}
	
	
	// Animation Setting
	
	
	//std::cout << playCoord.angle << std::endl;
	//std::cout << initialSpeed << std::endl;
	
}
