#include <string>
#include <iostream>
#include <string.h>
#include <SDL_image.h>

#ifndef animation_H
#define animation_H

class Animation {
	private:
		int frameCount;
		int currentFrame;
	public:
		SDL_Rect frameGrab();
		void setFrames(int frames);
	
};

#endif

