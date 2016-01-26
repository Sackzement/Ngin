#include "../include/Texture.h"
#include "../include/Renderer.h"
#include "../include/Surface.h"
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
bool Texture:: createFromSurface(Renderer& ren, Surface& surf) {

	m_sdlTexture = SDL_CreateTextureFromSurface(ren,surf);

	if (!m_sdlTexture) {

		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	return true;

}
bool Texture:: load(Renderer& ren,const std::string & file) {

	if (existsLoaded(ren,file)) {
		*this = ren.m_loadedTextures[file];
		return true;
	}

	if (Surface::existsLoaded(file)) {
		
		createFromSurface(ren, surf);
		return true;
	}
	m_sdlSurface = IMG_Load(file.c_str());

	if (!m_sdlSurface) {

		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	m_loadedSurfaces[file] = *this;

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
	m_sdlTexture = nullptr;
}

bool Texture:: existsLoaded(const Renderer& ren,const std::string & path) {

	try {
		const Texture & tex = ren.m_loadedTextures.at(path);
		if (tex.exists())
			return true;
		else
			return false;
	}
	catch (const std::out_of_range ex) {
		return false;
	}

}
void Texture:: destroyAllCreated(Renderer& ren) {

	auto it = ren.m_createdTextures.begin();
	auto end = ren.m_createdTextures.end();

	for (; it != end; ++it)
		it->destroy();

	ren.m_createdTextures.clear();

}
void Texture:: destroyAllLoaded(Renderer& ren) {

	auto it  = ren.m_loadedTextures.begin();
	auto end = ren.m_loadedTextures.end();

	for (; it != end; ++it)
		it->second.destroy();

	ren.m_loadedTextures.clear();

}
void Texture:: destroyAll(Renderer& ren) {

	destroyAllCreated(ren);
	destroyAllLoaded(ren);

}

Texture:: operator SDL_Texture *  () {
	return m_sdlTexture;
}