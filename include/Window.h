#pragma once

#include <SDL/SDL_video.h>
//#include "FlagsWindow.h"
#include <string>
class Renderer;

class Window
{
private:
	SDL_Window * m_sdlWindow;
public:
	bool create(const std::string& title,int x,int y,int w,int h,Uint32 flags);
	bool exists() const;
	void destroy();

	bool setFullscreen(Uint32 flag);

	bool     hasRenderer() const;
	Renderer getRenderer() const;
	Renderer createRenderer(int renidx, Uint32 flags);

};



