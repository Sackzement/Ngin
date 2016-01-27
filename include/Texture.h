#pragma once
#include <SDL/SDL_render.h>
#include <string>

class Renderer;
class Surface;



struct Texture {

	operator SDL_Texture * ();
	const int & width = m_width;
	const int & height = m_height;
private:
	SDL_Texture*  m_sdlTexture;
	int m_width;
	int m_height;
public:
	//object funcs
	Texture();
	bool create(Renderer& ren,Uint32 fmt,int access,int w,int h);
	bool createFromSurface(Renderer& ren, Surface& surf);
	bool load(Renderer& ren, const std::string & file);
	bool exists() const;
	void destroy();
private:
	static bool existsLoaded(const Renderer& ren,const std::string & path);
	static void destroyAllCreated(Renderer& ren);
	static void destroyAllLoaded(Renderer& ren);
public:
	static void destroyAll(Renderer& ren);

	Texture & operator = (const Texture & tex) {

		m_sdlTexture = tex.m_sdlTexture;
		m_width = tex.width;
		m_height = tex.height;
        
        return *this;
        
	}


};