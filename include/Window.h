#pragma once

#include <SDL/SDL_video.h>
#include "FlagsWindow.h"


class Window
{ 
private:
	SDL_Window* m_sdlWindow = nullptr;
public:
	bool create(const char* title, int xPos, int yPos, int width, int height, Uint32 flags);
	bool exists() const;
	bool setFullscreen(Uint32 flags);
	void destroy();

	operator SDL_Window * ();
};

static Window window;


