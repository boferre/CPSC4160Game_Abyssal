#include <iostream>
#include <string.h>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#include "graphics.h"
#include "AI.h"

// SDL initializer
void Graphics::SDL_Initialize(){
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
    }
    //Enable gpu_enhanced textures
    IMG_Init(IMG_INIT_PNG);
  
	my_window = SDL_CreateWindow("Abyssal", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       800,
			       600, 0);
	my_renderer = SDL_CreateRenderer(my_window,-1,0); 

}


void Graphics::StartScreen() {
	// Set background color
	SDL_SetRenderDrawColor(my_renderer, 3, 65, 65, 0);
    SDL_RenderPresent(my_renderer);
    aiController.createship(0, 700, 50, 87, 50, 180, "./Assets/Ships/Hunter/Cutter.png");
    aiController.createship(1, 20, 400, 400, 200, 0, "./Assets/Ships/Destroyer/HighCapital.png");
}


void Graphics::UpdateScreen() {
	SDL_RenderClear(my_renderer);
	PlayerUpdate();
	AIUpdate();
	SDL_RenderPresent(my_renderer);
}


int Graphics::fpsCount() {
    fpsCounter++;
    /*
    if (clock_Ticks >= (last_Clock_Ticks + 1000)) {
		last_Clock_Ticks = clock_Ticks;
		current_fps = fpsCounter;
		fpsCounter = 0;
	}*/
}


void Graphics::AnimationPlayer(int frames, int loop) {
	
}


void Graphics::PlayerUpdate() {
	playerController.playerController();
	
	SDL_Texture* textureHolder = NULL;
	SDL_Surface* surfaceHolder;
	
	SDL_Rect rect;
	rect.x = playerController.getPosX();
	rect.y = playerController.getPosY();
	rect.w = playerController.getWidth();
	rect.h = playerController.getHeight();
	
	surfaceHolder = IMG_Load(playerController.getShipFile());
	textureHolder = SDL_CreateTextureFromSurface(my_renderer, surfaceHolder);
	
	SDL_FreeSurface(surfaceHolder);
    //SDL_RenderCopy(my_renderer, textureHolder, NULL, &rect);
    SDL_RenderCopyEx(my_renderer, textureHolder, NULL, &rect, playerController.getAngle(), NULL, SDL_FLIP_NONE); 
}


void Graphics::AIUpdate() {
	SDL_Texture* textureHolder = NULL;
	SDL_Surface* surfaceHolder;
	
	aiController.AIControl(1, 'e');
	
	SDL_Rect rect;
	rect.x = aiController.getPositions(1).x;
	rect.y = aiController.getPositions(1).y;
	rect.w = aiController.getPositions(1).w;
	rect.h = aiController.getPositions(1).h;
	
	surfaceHolder = IMG_Load(aiController.getPositions(1).shipfile);
	textureHolder = SDL_CreateTextureFromSurface(my_renderer, surfaceHolder);
	
	SDL_FreeSurface(surfaceHolder);
    SDL_RenderCopy(my_renderer, textureHolder, NULL, &rect);
    
    
    aiController.AIControl(0, 'w');
    
    rect.x = aiController.getPositions(0).x;
	rect.y = aiController.getPositions(0).y;
	rect.w = aiController.getPositions(0).w;
	rect.h = aiController.getPositions(0).h;
	
	surfaceHolder = IMG_Load(aiController.getPositions(0).shipfile);
	textureHolder = SDL_CreateTextureFromSurface(my_renderer, surfaceHolder);
	
	SDL_FreeSurface(surfaceHolder);
    SDL_RenderCopyEx(my_renderer, textureHolder, NULL, &rect, aiController.getPositions(0).angle, NULL, SDL_FLIP_NONE); 
}


void cameraAdjust() {
	
	
}


/*
void EndGame() {
	SDL_DestroyRenderer(my_renderer);
	SDL_DestroyWindow(my_window);

	IMG_Quit();
	SDL_Quit();
}
*/
