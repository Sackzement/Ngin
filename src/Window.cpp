
#include "../include/Window.h"
#include "../include/Log.h"
#include "../include/Renderer.h"








bool Window::create(const std::string& title, int x, int y, int w, int h, Uint32 flags) {

	if (exists()) {

		Log("\nCan not create Window.  Window already exists.");
		return false;
	}

	m_sdlWindow = SDL_CreateWindow(title.c_str(),x,y,w,h,flags);

	if (!m_sdlWindow) {

		Log( std::string("\n") + SDL_GetError() );
		return false;
	}

	return true;
}

bool Window::exists() const {

	if (m_sdlWindow)
		return true;
	else
		return false;
}

void Window::destroy() {
	
	if (exists()) {
		SDL_DestroyWindow(m_sdlWindow);
		m_sdlWindow = nullptr;
	}
	else
		Log("\nNo Window to destroy.");
}


bool Window::setFullscreen(Uint32 flag) {

	if (SDL_SetWindowFullscreen(m_sdlWindow, flag) < 0) {
		Log(std::string("\n") + SDL_GetError());
		return false;
	}
	else
		return true;
}


bool     Window::hasRenderer() const {
	
	if (SDL_GetRenderer(m_sdlWindow))
		return true;
	else
		return false;

}
Renderer Window::getRenderer() const {

	Renderer ren;

	ren.m_sdlRenderer = SDL_GetRenderer(m_sdlWindow);

	return ren;

}
Renderer Window::createRenderer(int renidx,Uint32 flags) {

	Renderer ren;

	ren.m_sdlRenderer = SDL_CreateRenderer(m_sdlWindow, renidx, flags); 
	if (!ren.exists()) 
		Log(std::string("\n") + SDL_GetError());

	return ren;
}