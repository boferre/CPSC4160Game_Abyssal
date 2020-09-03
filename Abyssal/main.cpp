// CS 4160 - Abyssal V0.01 By Brandon Orion Ferrell

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

//Screen dimension
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* my_window = NULL;
SDL_Renderer* my_renderer = NULL;
SDL_Event input;

// SDL initializer
void my_SDL_init(){

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  my_window = SDL_CreateWindow("Abyssal", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       SCREEN_WIDTH,
			       SCREEN_HEIGHT, 0);
  my_renderer = SDL_CreateRenderer(my_window,-1,0);

}



int main() 
{ 
  my_SDL_init();
  
  // Add image
  SDL_Texture* ship_Texture = NULL;
  SDL_Surface* ship = IMG_Load("./Assets/Ships/AlphaShip.png");
  
  ship_Texture = SDL_CreateTextureFromSurface(my_renderer, ship);
  
  SDL_FreeSurface(ship);
  
  // Position image
  SDL_Rect rect;
  rect.x = 0;
  rect.y = 200;
  rect.w = 300;
  rect.h = 100;
  
  // Other variables
  bool game_Running = true;
  int clock_Ticks = 0;
  int fps_counter, current_fps, last_Clock_Ticks, fps_control = 0;
  int fps_Set = 14;
  
  // Main Game loop
  while(game_Running){
    
    // Get Clock Ticks
    clock_Ticks = SDL_GetTicks();
    
    // Move image
    rect.x += 1;
	// Check if at end of screen
	if ( rect.x > SCREEN_WIDTH)
		rect.x = 0;
		
	// Set background color
	SDL_SetRenderDrawColor(my_renderer, 0, 173, 216, 230);
	SDL_RenderClear(my_renderer);
    
    // Re render images
    SDL_RenderClear(my_renderer);
    SDL_RenderCopy(my_renderer, ship_Texture, NULL, &rect);
    SDL_RenderPresent(my_renderer);
    
    // FPS Counter
    fps_counter++;
    if (clock_Ticks >= (last_Clock_Ticks + 1000)) {
		last_Clock_Ticks = clock_Ticks;
		current_fps = fps_counter;
		fps_counter = 0;
	}
	std::cout << current_fps << std::endl;
	
	
	// FPS Controlls
	fps_control = SDL_GetTicks() - clock_Ticks;
	if (fps_control < fps_Set)
		SDL_Delay(fps_Set - fps_control);

  }

  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  
  return 0; 
}
