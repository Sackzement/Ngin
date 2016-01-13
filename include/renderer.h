#pragma once

#include <SDL/SDL_render.h>
#include "Window.h"
#include"FlagsRenderer.h"









class Renderer {
private:
	SDL_Renderer* m_sdlRenderer = nullptr;
public:
	bool create(Window& win, int index = -1, Uint32 flag =  Flags::Renderer::accelerated);
	void destroy();

	operator SDL_Renderer * const ();
};


