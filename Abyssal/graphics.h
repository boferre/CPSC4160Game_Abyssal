#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#ifndef graphic_H
#define graphic_H

class Graphics {
	private:
		SDL_Window* my_window;
		SDL_Renderer* my_renderer;
		
		
		
	public:
		int getScreenWidth() {return 800;};
		int getScreenHeight() {return 600;};
	
		void SDL_Initialize();
		void UpdateScreen();
		void PlaceObject(int x, int y, int w, int h, char* fileLocal);
		
		
};

#endif
