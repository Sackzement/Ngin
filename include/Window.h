#pragma once

#include <SDL/SDL_video.h>
#include "FlagsWindow.h"
#include <string>


class Window
{ 
private:
	SDL_Window * m_sdlWindow
public:
         Window();
    bool create(const std::string& title,int x,int y,int w,int h,Uint32 flags);
	bool exists() const;
	void destroy();
    
    bool setFullscreen(Uint32 flag);

    friend SDL_Window * Renderer::getWinPointer(Window& win);
};



