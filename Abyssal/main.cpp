// CS 4160 - Abyssal V0.02 By Brandon Orion Ferrell

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
  SDL_Surface* ship = IMG_Load("./Assets/Ships/MainShip.png");
  
  ship_Texture = SDL_CreateTextureFromSurface(my_renderer, ship);
  
  SDL_FreeSurface(ship);
  
  // Position image
  SDL_Rect rect;
  rect.x = 0;
  rect.y = 100;
  rect.w = 400;
  rect.h = 200;
  
  // Other variables
  bool game_Running = true;
  int clock_Ticks = 0;
  int fps_counter, current_fps, last_Clock_Ticks, fps_control, key_Press = 0;
  int fps_Set = 14;
  
  SDL_Event event_Handle;
  
  // Main Game loop
  while(game_Running){
    
    // Get Clock Ticks
    clock_Ticks = SDL_GetTicks();
	
	// User control input handlers
	while(SDL_PollEvent(&event_Handle) != 0) {
		if (event_Handle.type == SDL_QUIT) {
			std::cout << "Quiting" << std::endl;
			game_Running = false;
		} else if (event_Handle.type == SDL_KEYDOWN) {
			switch(event_Handle.key.keysym.sym ) {
				case SDLK_UP:
				std::cout << "UP" << std::endl;
				rect.y -= 1;
				if (rect.y <= 0)
					rect.y = 0;
				break;
				
				case SDLK_DOWN:
				std::cout << "DOWN" << std::endl;
				rect.y += 1;
				if (rect.y >= SCREEN_HEIGHT)
					rect.y = SCREEN_HEIGHT;
				break;
				
				case SDLK_LEFT:
				std::cout << "LEFT" << std::endl;
				rect.x -= 1;
				if (rect.x <= 0)
					rect.x = 0;
				break;
				
				case SDLK_RIGHT:
				std::cout << "RIGHT" << std::endl;
				rect.x += 1;
					if (rect.x >= SCREEN_WIDTH)
						rect.x = SCREEN_WIDTH;
				break;
			}
		}
    } 
		
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
	//std::cout << current_fps << std::endl;
	
	
	// FPS Controlls
	fps_control = SDL_GetTicks() - clock_Ticks;
	if (fps_control < fps_Set)
		SDL_Delay(fps_Set - fps_control);

  }
  
  std::cout << "Shutting down" << std::endl;
  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  
  return 0; 
}
