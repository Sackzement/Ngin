#pragma once
#include <SDL/SDL_render.h>
#include <string>

class Renderer;
class Surface;



struct Texture {
private:
	SDL_Texture* m_sdlTexture;
	int m_width;
	int m_height;
public:
	Texture();
	bool exists() const;
	void destroy();
    
    int getWidth() const;
    int getHeight() const;
    // can be deleted after this
private:
	static bool existsLoaded(const Renderer& ren,const std::string & path);
	static void destroyAllCreated(Renderer& ren);
	static void destroyAllLoaded(Renderer& ren);
public:
	static void destroyAll(Renderer& ren);

	Texture & operator = (const Texture & tex) {

		m_sdlTexture = tex.m_sdlTexture;
		m_width = tex.m_width;
		m_height = tex.m_height;
        
        return *this;
        
	}


};