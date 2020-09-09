#include <iostream>
#include <string.h>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#include "player.h"

bool Player::playerController() {
	SDL_Event handler;	
	
	while(SDL_PollEvent(&handler) != 0) {
		if (handler.type == SDL_QUIT) {
			std::cout << "Quiting" << std::endl;
			return false;
		} else if (handler.type == SDL_KEYDOWN) {
			switch(handler.key.keysym.sym ) {
				case SDLK_UP:
				playCoord.y -= shipSpeed;
				break;
				
				case SDLK_DOWN:
				playCoord.y += shipSpeed;
				break;
				
				case SDLK_LEFT:
				playCoord.x -= shipSpeed;
				break;
				
				case SDLK_RIGHT:
				playCoord.x += shipSpeed;
				break;
			} 
		}
		return true;
	}
}
