
#include "../include/window.h"
#include "sdlWindow.h"
#include <SDL/SDL.h>


CWindow window;







bool CWindow::create(cchar* title, int xPos, int yPos, int width, int height, uint flag) {

	if (sdlWindow)
	{
		SDL_Log("Window already created");
		return true;
	}

	sdlWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flag);
	if (!sdlWindow)
	{
		SDL_Log("Error:  Failed to create window  %s", SDL_GetError() );
		return false;
	}
	else
	{
   		return true;
	}
}

void CWindow::destroy() {
	
	SDL_DestroyWindow(sdlWindow);
	sdlWindow = nullptr;
}


bool CWindow::setFullscreen(uint flag) {

	if (SDL_SetWindowFullscreen(sdlWindow, flag) < 0) {
		SDL_Log("Error:  Failed to set Fullscreen    %s", SDL_GetError());
		return false;
	}
	else
		return true;
}
