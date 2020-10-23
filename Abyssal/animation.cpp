#include "animation.h"

SDL_Rect Animation::frameGrab(int imageX, int imageY, int imageH, int imageW, int afterStart) {
	SDL_Rect frame;
	if (currentFrame >= (frameCount))
		currentFrame = afterStart;
	
	frame.x = imageX + (imageW * currentFrame);
	frame.y = imageY;
	frame.h = imageH;
	frame.w = imageW;
	
	currentFrame++;
	return frame;
}
