#pragma once

#include "../include/renderer.h"
#include "../include/window.h"
#include "../include/sdlRenderer.h"


CrendererFlags::CrendererFlags() :
	software(SDL_RENDERER_SOFTWARE),
	accel(SDL_RENDERER_ACCELERATED),
	vsync(SDL_RENDERER_PRESENTVSYNC),
	texture(SDL_RENDERER_TARGETTEXTURE)
{}





CRenderer renderer;






bool CRenderer::create(int index, uint flag)
{
	if (m_sdlRenderer) 
		return true;

	//m_sdlRenderer = SDL_GetRenderer(m_sdlWindow);
	if (m_sdlRenderer)
		return true;

	//m_sdlRenderer = SDL_CreateRenderer(m_sdlWindow, index, flag);
	if (!m_sdlRenderer) {
		SDL_Log("Error:  Failed to create renderer  %s", SDL_GetError());
		return false;
	}

	return true;
}



void CRenderer::destroy() {

	SDL_DestroyRenderer(m_sdlRenderer);
	m_sdlRenderer = nullptr;
}