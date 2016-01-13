
#include "../include/Window.h"
#include <SDL/SDL_Log.h>










bool Window::create(const char* title, int xPos, int yPos, int width, int height, Uint32 flag) {

	if (m_sdlWindow)
	{
		SDL_Log("Window already created");
		return true;
	}

	m_sdlWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flag);
	if (!m_sdlWindow)
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
	
	SDL_DestroyWindow(m_sdlWindow);
	m_sdlWindow = nullptr;
}


bool Window::setFullscreen(Uint32 flag) {

	if (SDL_SetWindowFullscreen(m_sdlWindow, flag) < 0) {
		SDL_Log("Error:  Failed to set Fullscreen    %s", SDL_GetError());
		return false;
	}
	else
		return true;
}


Window:: operator SDL_Window * const () {
	return m_sdlWindow;
}