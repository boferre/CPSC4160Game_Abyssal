#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "AI.h"
#include "player.h"

#ifndef graphic_H
#define graphic_H

class Graphics {
	private:
		SDL_Window* my_window;
		SDL_Renderer* my_renderer;
		
		AI aiController;
		Player playerController;
		
		int fpsCounter = 0;
		
		const int WINDOW_WIDTH = 640;
		const int WINDOW_HEIGHT = 480;
		
		const int LEVEL_WIDTH = 2000;
		const int LEVEL_HEIGHT = 1000;
		
	public:
		//Graphics();
	
		int getScreenWidth() {return LEVEL_WIDTH;};
		int getScreenHeight() {return LEVEL_HEIGHT;};
		int getCameraWidth() {return WINDOW_WIDTH;};
		int getCameraHeight() {return WINDOW_HEIGHT;};
	
		void SDL_Initialize();
		void StartScreen();
		void UpdateScreen();
		
		void AnimationPlayer(int frames, int loop);
		void PlayerUpdate();
		void AIUpdate();
		
		void cameraAdjust(); 
		
		int fpsCount();
		
		
};

#endif
