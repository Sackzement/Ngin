
#include "../include/Renderer.h"
#include "../include/Log.h"
#include "../include/Texture.h"
#include <SDL/SDL_image.h>
#include "../include/Surface.h"












Renderer:: Renderer() : m_sdlRenderer(nullptr) {}

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
bool Renderer:: setTarget(SDL_Texture * tex) 

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
/*bool Renderer:: load(const std::string & path) {
	
	if (existsTexture(path))
		return true;

	Surface surf;
	surf.load(path.c_str());

	if (surf.exists()) {
		Texture newTex;
		newTex.createFromSurface(*this,surf);
		surf.free();
	}
}*/
/*void Renderer::unload(std::string path) {

if ( existsTexture )
SDL_DestroyTexture(m_sdlTexture);
}
void Renderer:: unload(std::vector<std::string> list) {

}*/  


Renderer:: operator SDL_Renderer *  () {
	return m_sdlRenderer;
}


