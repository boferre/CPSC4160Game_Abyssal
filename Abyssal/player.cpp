#include "player.h"

bool Player::playerController() {
	SDL_Event handler;	
	
	playCoord.animState = 0;
	playCoord.animStart = 0;
	
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
						playCoord.angle -= 2;
					}
				break;
				
				// Turn right
				case SDLK_RIGHT:
					if (playCoord.angle >= 360) {
						playCoord.angle = 0;
					} else {
							playCoord.angle += 2;
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
		} else if (playCoord.angle <= 110 && playCoord.angle >= 71) {
			playCoord.y += initialSpeed;
		} else if (playCoord.angle <= 339 && playCoord.angle >= 290) {
			playCoord.x += initialSpeed;
			playCoord.y -= initialSpeed;
		} else if (playCoord.angle <= 289 && playCoord.angle >= 250) {
			playCoord.y -= initialSpeed;
		} else if (playCoord.angle <= 249 && playCoord.angle >= 200) {
			playCoord.x -= initialSpeed;
			playCoord.y -= initialSpeed;
		} else if (playCoord.angle <= 199 && playCoord.angle >= 161) {
			playCoord.x -= initialSpeed;
		}                     
	}
	
	// Boundary checks
	if (playCoord.x < 0)
		playCoord.x -= initialSpeed;
	if (playCoord.x + playCoord.w > LEVEL_WIDTH)
		playCoord.x = LEVEL_WIDTH - playCoord.w;
	if (playCoord.y < 0)
		playCoord.y -= initialSpeed;
	if (playCoord.y + playCoord.h > LEVEL_HEIGHT)
		playCoord.y = LEVEL_HEIGHT - playCoord.h;
	
	// Animation Setting
	if (initialSpeed > 0)
		playCoord.animState = 5;
		playCoord.animStart = 2;
	if (initialSpeed < 0)
		playCoord.animState = -5;
		playCoord.animStart = 2;
		
	// Animation Apply
	switch (playCoord.animState) {
			case 0:
				playCoord.w = 27;
				playCoord.imageX = 0;
				playCoord.imageY = 0;
			break;
			
			case 5:
				playCoord.w = 37;
				playCoord.imageX = 0;
				playCoord.imageY = 20;
			break;
			
			case -5:
				playCoord.w = 37;
				playCoord.imageX = 0;
				playCoord.imageY = 40;
			break;
	}
	
	//std::cout << playCoord.x << std::endl;
	//std::cout << playCoord.angle << std::endl;
	//std::cout << initialSpeed << std::endl;
	
}
