#include <iostream>
#include <string.h>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#include "graphics.h"

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


void Graphics::UpdateScreen() {
	// Set background color
	SDL_SetRenderDrawColor(my_renderer, 0, 173, 216, 230);
	SDL_RenderClear(my_renderer);
    SDL_RenderPresent(my_renderer); 
}


void Graphics::PlaceObject(int x, int y, int w, int h, char* fileLocal) {
	SDL_Texture* textureHolder = NULL;
	SDL_Surface* surfaceHolder;
	
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	
	surfaceHolder = IMG_Load(fileLocal);
	textureHolder = SDL_CreateTextureFromSurface(my_renderer, surfaceHolder);
	
	SDL_FreeSurface(surfaceHolder);
	
	SDL_RenderClear(my_renderer);
    SDL_RenderCopy(my_renderer, textureHolder, NULL, &rect);
    SDL_RenderPresent(my_renderer);
}

/*
int fpsController() {
	return 1;
}


void DisplayImage(int x, int y, int w, int h, char* surfacefile) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	
	SurfaceHolder = IMG_Load(surfacefile);
	TextureHolder = SDL_CreateTextureFromSurface(my_renderer, SurfaceHolder);
	
	SDL_FreeSurface(SurfaceHolder);
	
	SDL_RenderClear(my_renderer);
    SDL_RenderCopy(my_renderer, TextureHolder, NULL, &rect);
    SDL_RenderPresent(my_renderer);
	
}


void EndGame() {
	SDL_DestroyRenderer(my_renderer);
	SDL_DestroyWindow(my_window);

	IMG_Quit();
	SDL_Quit();
}
*/
