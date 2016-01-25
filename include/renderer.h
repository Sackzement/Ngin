#pragma once

#include <SDL/SDL_render.h>
#include "Window.h"
#include"FlagsRenderer.h"

#include <vector>






//class Texture;
#include "Texture.h"


#include <map>
 
class Renderer {

private:  // variables
	SDL_Renderer*                  m_sdlRenderer;
	std::map<const std::string,Texture>  m_textures;
public: // object funcs
	Renderer();
	bool create(Window& win, int index, Uint32 flags);
	bool exists() const;
	void destroy();
	// draw funcs
	bool setTarget(SDL_Texture * target);
	bool clear();
	bool copy(Texture & tex, const SDL_Rect * srcrect, const SDL_Rect * dstrect);
	bool copyEx(Texture & tex, const SDL_Rect * srcrect, const SDL_Rect * dstrect,
						double angle, const SDL_Point* center, SDL_RendererFlip flip);
	// texture manager funcs
	bool load(const std::string & path);
	bool load(const std::vector<const std::string> & list);
	bool existsTexture(const std::string & path) const;
	//void unload(std::string path);
	//void unload(std::vector<std::string> list);
	void unloadAll();

	operator SDL_Renderer * ();
};


//static Renderer renderer;

