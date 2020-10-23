#include <string>
#include <iostream>
#include <string.h>
#include <SDL_image.h>

#ifndef animation_H
#define animation_H

class Animation {
	private:
		int frameCount;
		int currentFrame = 0;
	public:
		SDL_Rect frameGrab(int imageX, int imageY, int imageH, int imageW, int afterStart);
		void setFrames(int frames) {frameCount = abs(frames);};
	
};

#endif

