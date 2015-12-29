
#include "../include/renderer.h"
#include "sdlWindow.h"
#include "sdlRenderer.h"
#include <SDL/SDL_log.h>


CRenderer renderer;




CRendererFlags::CRendererFlags() :
	software(SDL_RENDERER_SOFTWARE),
	accel(SDL_RENDERER_ACCELERATED),
	vsync(SDL_RENDERER_PRESENTVSYNC),
	texture(SDL_RENDERER_TARGETTEXTURE)
{}









bool CRenderer::create(int index, int flag)
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



void CRenderer::destroy() {

	SDL_DestroyRenderer(sdlRenderer);
	sdlRenderer = nullptr;
}