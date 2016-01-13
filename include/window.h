#pragma once

#include <SDL/SDL_video.h>
#include "FlagsWindow.h"


class Window
{ 
private:
	SDL_Window* m_sdlWindow = nullptr;
public:
	bool create(const char* title = "Game", int xPos = 100, int yPos = 100, int width = 951, int height = 540, Uint32 flag = Flags::Window::shown);
	bool setFullscreen(Uint32 flag = Flags::Window::fullscreenDesktop);
	void destroy();

	operator SDL_Window * const ();
};


