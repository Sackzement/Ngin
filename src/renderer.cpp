
#include "../include/Renderer.h"
#include <SDL/SDL_log.h>














bool Renderer::create(Window& win, int index, Uint32 flag)
{
	if (m_sdlRenderer)
		return true;

	m_sdlRenderer = SDL_GetRenderer(win);
	if (m_sdlRenderer)
		return true;

	m_sdlRenderer = SDL_CreateRenderer(win, index, flag);
	if (!m_sdlRenderer) {
		SDL_Log("Error:  Failed to create renderer  %s", SDL_GetError());
		return false;
	}

	return true;
}



void Renderer::destroy() {

	SDL_DestroyRenderer(m_sdlRenderer);
	m_sdlRenderer = nullptr;
}


Renderer:: operator SDL_Renderer * const () {
	return m_sdlRenderer;
}