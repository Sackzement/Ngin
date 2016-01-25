
#include "../include/Renderer.h"
#include "../include/Log.h"
#include "../include/Texture.h"
#include <SDL/SDL_image.h>
//#include <SDL/SDL_surface.h>












// object funcs
     Renderer:: Renderer()

	: m_sdlRenderer (nullptr),
	  m_textures    (std::map<const std::string,Texture>())

{}
bool Renderer:: create(Window& win, int index, Uint32 flags)
{
	if (exists()) {
		Log("\nCan not create Renderer. Renderer already exists.");
		return false;
	}

	m_sdlRenderer = SDL_GetRenderer(win);
	if (m_sdlRenderer) {
		Log("\nCan not create Renderer. Window already has a Renderer.");
		return false;
	}

	m_sdlRenderer = SDL_CreateRenderer(win, index, flags);
	if (!m_sdlRenderer) {
		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	return true;
}
bool Renderer:: exists() const {
	if (m_sdlRenderer)
		return true;
	else
		return false;
}
void Renderer:: destroy() {

	if (exists()) {
		SDL_DestroyRenderer(m_sdlRenderer);
		m_sdlRenderer = nullptr;
	}
	else
		Log("\nNo Renderer to destroy.");
}
// draw funcs
bool Renderer:: setTarget(SDL_Texture * tex) {

	if (SDL_SetRenderTarget(m_sdlRenderer, nullptr) < 0) {
		
		Log(std::string("\n") + SDL_GetError());
		return false;
	}
	else
		return true;
}
bool Renderer:: clear() {

	if (SDL_RenderClear(m_sdlRenderer) < 0) {

		Log(std::string("\n") + SDL_GetError());
		return false;
	}
	else
		return true;
}
bool Renderer:: copy  (Texture & tex, const SDL_Rect * srcrect, const SDL_Rect * dstrect) {

	if (SDL_RenderCopy(m_sdlRenderer, tex, srcrect, dstrect) < 0) {

		Log(std::string("\n") + SDL_GetError());
		return false;
	}
	else
		return true;
}
bool Renderer:: copyEx(Texture & tex, const SDL_Rect * srcrect, const SDL_Rect * dstrect,
								double angle, const SDL_Point* center, SDL_RendererFlip flip) {

	if ( SDL_RenderCopyEx(m_sdlRenderer, tex, srcrect, dstrect, angle, center, flip) < 0) {

		Log(std::string("\n") + SDL_GetError());
		return false;
	}
	else
		return true;
}
// texture manager funcs
bool Renderer:: load(const std::string & path) {
	
	if (existsTexture(path))
		return true;

	SDL_Surface* temp_surf = IMG_Load(path.c_str());

	if (!temp_surf)
		Log(std::string("\n") + SDL_GetError());
	else {
		Texture newTex;
		newTex.createFromSurface(*this, temp_surf);

		SDL_FreeSurface(temp_surf);
	}
}
bool Renderer:: load(const std::vector<const std::string> & list) {
	return false;
}
bool Renderer:: existsTexture(const std::string & path) const {

	try {
		const Texture & tex = m_textures.at(path);
		if (tex.exists())
			return true;
		else
			return false;
	}
	catch (const std::out_of_range ex) {
		return false;
	}

}
/*void Renderer::unload(std::string path) {

if ( existsTexture )
SDL_DestroyTexture(m_sdlTexture);
}
void Renderer:: unload(std::vector<std::string> list) {

}*/  
void Renderer:: unloadAll() {

	auto it = m_textures.begin();
	auto end = m_textures.end();

	for (; it != end; ++it)
		it->second.destroy();

	m_textures.clear();
}

Renderer:: operator SDL_Renderer *  () {
	return m_sdlRenderer;
}


