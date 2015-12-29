
#include "../include/window.h"
#include "sdlWindow.h"
#include <SDL/SDL.h>


CWindow window;



CWindowFlags:: CWindowFlags() :
	fullscreen         (SDL_WINDOW_FULLSCREEN),
	opengl             (SDL_WINDOW_OPENGL),
	shown              (SDL_WINDOW_SHOWN),
	hidden             (SDL_WINDOW_HIDDEN),
	borderless         (SDL_WINDOW_BORDERLESS),
	resizable          (SDL_WINDOW_RESIZABLE),
	minimized          (SDL_WINDOW_MINIMIZED),
	maximized          (SDL_WINDOW_MAXIMIZED),
	inputGrabbed       (SDL_WINDOW_INPUT_GRABBED),
	inputFocus         (SDL_WINDOW_INPUT_FOCUS),
	mouseFocus         (SDL_WINDOW_MOUSE_FOCUS),
	fullscreenDesktop  (SDL_WINDOW_FULLSCREEN_DESKTOP),
	foreign            (SDL_WINDOW_FOREIGN),
	allowHighDPI       (SDL_WINDOW_ALLOW_HIGHDPI),
	mouseCapture       (SDL_WINDOW_MOUSE_CAPTURE)
	{}




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
