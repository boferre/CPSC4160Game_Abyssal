#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "AI.h"

#ifndef graphic_H
#define graphic_H

class Graphics {
	private:
		SDL_Window* my_window;
		SDL_Renderer* my_renderer;
		
		char* playerShip;
		AI aiController;
		
		int fpsCounter = 0;
		
	public:
		int getScreenWidth() {return 800;};
		int getScreenHeight() {return 600;};
	
		void SDL_Initialize();
		void StartScreen(char* fileLocal);
		void UpdateScreen(int x, int y, int w, int h);
		void AnimationPlayer(int frames, int loop);
		void PlayerUpdate(int x, int y, int w, int h);
		void AIUpdate();
		
		int fpsCount();
		
		
};

#endif
