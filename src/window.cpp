
#include "../include/window.h"
#include "sdlWindow.h"
#include <SDL/SDL.h>





const int WindowFlags::fullscreen = SDL_WINDOW_FULLSCREEN;
const int WindowFlags::opengl =SDL_WINDOW_OPENGL;
const int WindowFlags::shown =SDL_WINDOW_SHOWN;
const int WindowFlags::hidden =SDL_WINDOW_HIDDEN;
const int WindowFlags::borderless =SDL_WINDOW_BORDERLESS;
const int WindowFlags::resizable =SDL_WINDOW_RESIZABLE;
const int WindowFlags::minimized =SDL_WINDOW_MINIMIZED;
const int WindowFlags::maximized =SDL_WINDOW_MAXIMIZED;
const int WindowFlags::inputGrabbed =SDL_WINDOW_INPUT_GRABBED;
const int WindowFlags::inputFocus =SDL_WINDOW_INPUT_FOCUS;
const int WindowFlags::mouseFocus =SDL_WINDOW_MOUSE_FOCUS;
const int WindowFlags::fullscreenDesktop =SDL_WINDOW_FULLSCREEN_DESKTOP;
const int WindowFlags::foreign =SDL_WINDOW_FOREIGN;
const int WindowFlags::allowHighDPI =SDL_WINDOW_ALLOW_HIGHDPI;
const int WindowFlags::mouseCapture =SDL_WINDOW_MOUSE_CAPTURE;




bool Window::create(cchar* title, int xPos, int yPos, int width, int height, uint flag) {

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

void Window::destroy() {
	
	SDL_DestroyWindow(sdlWindow);
	sdlWindow = nullptr;
}


bool Window::setFullscreen(uint flag) {

	if (SDL_SetWindowFullscreen(sdlWindow, flag) < 0) {
		SDL_Log("Error:  Failed to set Fullscreen    %s", SDL_GetError());
		return false;
	}
	else
		return true;
}
