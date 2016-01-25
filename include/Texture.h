#pragma once
#include <SDL/SDL_render.h>

class Renderer;




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
	bool createFromSurface(Renderer& ren, SDL_Surface* surf);
	bool exists() const;
	void destroy();

	Texture & operator = (const Texture & tex) {

		m_sdlTexture = tex.m_sdlTexture;
		m_width = tex.width;
		m_height = tex.height;
	}


};