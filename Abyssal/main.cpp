// CS 4160 - Abyssal V0.02 By Brandon Orion Ferrell

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

//Screen dimension
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

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


//Simple Player controller
bool playerController(SDL_Rect& shipsRect, SDL_Event& handler) {
	while(SDL_PollEvent(&handler) != 0) {
		if (handler.type == SDL_QUIT) {
			std::cout << "Quiting" << std::endl;
			return false;
		} else if (handler.type == SDL_KEYDOWN) {
			switch(handler.key.keysym.sym ) {
				case SDLK_UP:
				std::cout << "UP" << std::endl;
				shipsRect.y -= 1;
				if (shipsRect.y <= 0)
					shipsRect.y = 0;
				break;
				
				case SDLK_DOWN:
				std::cout << "DOWN" << std::endl;
				shipsRect.y += 1;
				if (shipsRect.y >= SCREEN_HEIGHT)
					shipsRect.y = SCREEN_HEIGHT;
				break;
				
				case SDLK_LEFT:
				std::cout << "LEFT" << std::endl;
				shipsRect.x -= 1;
				if (shipsRect.x <= 0)
					shipsRect.x = 0;
				break;
				
				case SDLK_RIGHT:
				std::cout << "RIGHT" << std::endl;
				shipsRect.x += 1;
					if (shipsRect.x >= SCREEN_WIDTH)
						shipsRect.x = SCREEN_WIDTH;
				break;
			}
			return true;
		}
    }
}


int fpsController() {
	
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
	playerController(rect, event_Handle);
		
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
