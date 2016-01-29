#pragma once
#include <SDL/SDL_render.h>
#include <string>

class Renderer;
class Surface;



struct Texture {
private:
	SDL_Texture * m_sdlTexture;
	int m_width;
	int m_height;
public:
	     Texture();
	bool exists() const;
	void destroy();
    
    int getWidth() const;
    int getHeight() const;
};