// CS 4160 - Abyssal V0.02 By Brandon Orion Ferrell

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

// custom files
#include "graphics.h"
#include "player.h"

int main() 
{ 
  
  // Other variables
  bool game_Running = true;
  int clock_Ticks = 0;
  int fps_counter, current_fps, last_Clock_Ticks, fps_control, key_Press = 0;
  int fps_Set = 14;
  
  // Activate Controllers
  Graphics graphicController;
  Player playerController;
  
  // Starting initialization
  graphicController.SDL_Initialize();
  graphicController.UpdateScreen();
  
  // Main Game loop
  while(game_Running){
    
    // Get Clock Ticks
    //clock_Ticks = SDL_GetTicks();
	
	// User control input handlers
	playerController.playerController();
	
	//Graphics Controlls
	graphicController.PlaceObject(playerController.getPosX(), playerController.getPosY(), 400, 200, "./Assets/Ships/Destroyer/HighCapital.png");
    
    /*// FPS Counter
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
		SDL_Delay(fps_Set - fps_control);*/

  }
  
  std::cout << "Shutting down" << std::endl;
  
  
  return 0; 
}
