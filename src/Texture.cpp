#include "../include/Texture.h"
#include "../include/Renderer.h"
#include "../include/Log.h"

Texture::Texture()

  : m_sdlTexture (nullptr),
	width        (m_width),
	height       (m_height),

	m_width      (0),
	m_height     (0)

	{}
bool Texture:: create(Renderer& ren,Uint32 fmt,int acc,int w,int h) {

	m_sdlTexture = SDL_CreateTexture(ren,fmt,acc,w,h);

	if (!m_sdlTexture) {

		Log(std::string("\n") + SDL_GetError());
		return false;
	}
	
	return true;

}
bool Texture::createFromSurface(Renderer& ren, SDL_Surface* surf) {

	m_sdlTexture = SDL_CreateTextureFromSurface(ren,surf);

	if (!m_sdlTexture) {

		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	return true;

}
bool Texture:: exists() const {

	if (m_sdlTexture)
		return true;
	else
		return false;
}
void Texture:: destroy() {

	SDL_DestroyTexture(m_sdlTexture);
}

Texture:: operator SDL_Texture *  () {
	return m_sdlTexture;
}