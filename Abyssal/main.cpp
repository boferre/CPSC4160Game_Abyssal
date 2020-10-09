// CS 4160 - Abyssal V0.02 By Brandon Orion Ferrell

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

// custom files
#include "graphics.h"

int main() 
{ 
  
  // Other variables
  bool game_Running = true;
  int clock_Ticks = 0;
  int fps_counter, current_fps, last_Clock_Ticks, fps_control, key_Press = 0;
  int fps_Set = 14;
  
  // Activate Controllers
  Graphics graphicController;
  
  // Starting initialization
  graphicController.SDL_Initialize();
  graphicController.StartScreen();
  
  // Main Game loop
  while(game_Running){
    
    // Get Clock Ticks
    clock_Ticks = SDL_GetTicks();
	
	//Graphics Controlls
	graphicController.UpdateScreen();
    
    // FPS Counter
    fps_counter++;
    if (clock_Ticks >= (last_Clock_Ticks + 1000)) {
		last_Clock_Ticks = clock_Ticks;
		current_fps = fps_counter;
		fps_counter = 0;
	}
	std::cout << current_fps << std::endl;


  }
  
  std::cout << "Shutting down" << std::endl;
  
  
  return 0; 
}
