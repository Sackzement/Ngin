
#include "../include/renderer.h"
#include "sdlWindow.h"
#include "sdlRenderer.h"
#include <SDL/SDL_log.h>






const int RendererFlags::software = SDL_RENDERER_SOFTWARE;
const int RendererFlags::accel = SDL_RENDERER_ACCELERATED;
const int RendererFlags::vsync = SDL_RENDERER_PRESENTVSYNC;
const int RendererFlags::texture = SDL_RENDERER_TARGETTEXTURE;










bool Renderer::create(int index, int flag)
{
	if (sdlRenderer)
		return true;

	sdlRenderer= SDL_GetRenderer(sdlWindow);
	if (sdlRenderer)
		return true;

	sdlRenderer = SDL_CreateRenderer(sdlWindow, index, flag);
	if (!sdlRenderer) {
		SDL_Log("Error:  Failed to create renderer  %s", SDL_GetError());
		return false;
	}

	return true;
}



void Renderer::destroy() {

	SDL_DestroyRenderer(sdlRenderer);
	sdlRenderer = nullptr;
}