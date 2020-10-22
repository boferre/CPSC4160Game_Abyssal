#include <iostream>
#include <string>

#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>
#include "AI.h"
#include "player.h"
#include "animation.h"

#ifndef graphic_H
#define graphic_H

class Graphics {
	private:
		SDL_Window* my_window;
		SDL_Renderer* my_renderer;
		
		AI aiController;
		Player playerController;
		
		int fpsCounter = 0;
		
		
		const int LEVEL_WIDTH = 852;
		const int LEVEL_HEIGHT = 480;
		
		SDL_Rect cameraRect = {0, 0, 640, 480};
		
	public:
		//Graphics();
	
		int getLevelWidth() {return LEVEL_WIDTH;};
		int getLevelHeight() {return LEVEL_HEIGHT;};
		int getCameraWidth() {return cameraRect.w;};
		int getCameraHeight() {return cameraRect.h;};
	
		void SDL_Initialize();
		void StartScreen();
		void UpdateScreen();

		void PlayerUpdate();
		void AIUpdate();
		
		void cameraAdjust();
		void backgroundUpdate();
		
		int fpsCount();
		
		
};

#endif
