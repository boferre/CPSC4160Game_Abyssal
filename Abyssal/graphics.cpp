#include "graphics.h"

// SDL initializer
void Graphics::SDL_Initialize(){
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
    }
    //Enable gpu_enhanced textures
    IMG_Init(IMG_INIT_PNG);
  
	my_window = SDL_CreateWindow("Abyssal", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       getCameraWidth(),
			       getCameraHeight(), 0);
			       
	my_renderer = SDL_CreateRenderer(my_window,-1,0); 

}


void Graphics::StartScreen() {
	// Set background color
	//SDL_SetRenderDrawColor(my_renderer, 3, 65, 65, 0);
    SDL_RenderPresent(my_renderer);
}


void Graphics::UpdateScreen() {
	playerController.playerController();
	cameraAdjust();
	SDL_RenderClear(my_renderer);
	backgroundUpdate();
	PlayerUpdate();
	SDL_RenderPresent(my_renderer);
}


int Graphics::fpsCount() {
    fpsCounter++;
    /*
    if (clock_Ticks >= (last_Clock_Ticks + 1000)) {
		last_Clock_Ticks = clock_Ticks;
		current_fps = fpsCounter;
		fpsCounter = 0;
	}*/
}


void Graphics::PlayerUpdate() {
	
	
	SDL_Texture* textureHolder = NULL;
	SDL_Surface* surfaceHolder;
	SDL_Rect frame;
	SDL_Rect rect;
	rect.x = playerController.getPosX() - cameraRect.x;
	rect.y = playerController.getPosY() - cameraRect.y;
	rect.w = playerController.getWidth() * 2;
	rect.h = playerController.getHeight() * 2;
	playAnimator.setFrames(playerController.getState());
	frame = playAnimator.frameGrab(playerController.getImageX(), playerController.getImageY(), playerController.getHeight(), playerController.getWidth(), 0);
	surfaceHolder = IMG_Load(playerController.getShipFile());
	textureHolder = SDL_CreateTextureFromSurface(my_renderer, surfaceHolder);
	
	
	
	SDL_FreeSurface(surfaceHolder);
    SDL_RenderCopyEx(my_renderer, textureHolder, &frame, &rect, playerController.getAngle(), NULL, SDL_FLIP_NONE); 
}


void Graphics::AIUpdate() {
	SDL_Texture* textureHolder = NULL;
	SDL_Surface* surfaceHolder;
	
	aiController.AIControl(1, 'e');
	
	SDL_Rect rect;
	rect.x = aiController.getPositions(1).x;
	rect.y = aiController.getPositions(1).y;
	rect.w = aiController.getPositions(1).w;
	rect.h = aiController.getPositions(1).h;
	
	surfaceHolder = IMG_Load(aiController.getPositions(1).shipfile);
	textureHolder = SDL_CreateTextureFromSurface(my_renderer, surfaceHolder);
	
	SDL_FreeSurface(surfaceHolder);
    SDL_RenderCopy(my_renderer, textureHolder, NULL, &rect);
    
    
    aiController.AIControl(0, 'w');
    
    rect.x = aiController.getPositions(0).x;
	rect.y = aiController.getPositions(0).y;
	rect.w = aiController.getPositions(0).w;
	rect.h = aiController.getPositions(0).h;
	
	surfaceHolder = IMG_Load(aiController.getPositions(0).shipfile);
	textureHolder = SDL_CreateTextureFromSurface(my_renderer, surfaceHolder);
	
	SDL_FreeSurface(surfaceHolder);
    SDL_RenderCopyEx(my_renderer, textureHolder, NULL, &rect, aiController.getPositions(0).angle, NULL, SDL_FLIP_NONE); 
}


void Graphics::cameraAdjust() {
	cameraRect.x = (playerController.getPosX() - playerController.getWidth() / 2 ) - getCameraWidth() / 2;
	cameraRect.y = (playerController.getPosY() - playerController.getHeight() / 2 ) - getCameraHeight() / 2;
	
	if (cameraRect.x < 0)
		cameraRect.x = 0;
	if (cameraRect.y < 0)
		cameraRect.y = 0;
	if (cameraRect.x > LEVEL_WIDTH - cameraRect.w)
		cameraRect.x = LEVEL_WIDTH - cameraRect.w;
	if (cameraRect.y > LEVEL_HEIGHT - cameraRect.h)
		cameraRect.y = LEVEL_HEIGHT - cameraRect.h;
}


void Graphics::backgroundUpdate() {
	SDL_Texture* textureHolder = NULL;
	SDL_Surface* surfaceHolder;
	
	surfaceHolder = IMG_Load("./Assets/background.jpg");
	textureHolder = SDL_CreateTextureFromSurface(my_renderer, surfaceHolder);
	
	SDL_FreeSurface(surfaceHolder);
	
	SDL_Rect renderArea = {0, 0, 0, 0};
	renderArea.w = cameraRect.w;
	renderArea.h = cameraRect.h;
	
    SDL_RenderCopyEx(my_renderer, textureHolder, &cameraRect, &renderArea, 0, NULL, SDL_FLIP_NONE);
}


/*
void EndGame() {
	SDL_DestroyRenderer(my_renderer);
	SDL_DestroyWindow(my_window);

	IMG_Quit();
	SDL_Quit();
}
*/
