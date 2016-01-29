#pragma once

#include <SDL/SDL_render.h>
#include "Window.h"
#include"FlagsRenderer.h"

#include <vector>






//class Texture;
#include "Texture.h"


#include <map>
 
class Renderer {
private:
	SDL_Renderer* m_sdlRenderer;
public:
         Renderer();
	bool create(Window& win,int renidx,Uint32 flags);
	bool exists() const;
	void destroy();
    
    Texture createTexture(Uint32 fmt,int acc,int w,int h);
    Texture createTexture(Surface& surf);
    
    bool setTarget(Texture& tex);
    bool setTargetDefault();
    bool setColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a);
    bool clear();
    bool copy(Texture& tex,int x,int y,int w,int h);
    bool copyEx(Texture& tex,int x,int y,int w,int h,double rot,int flip); // Flip flip
private:
    static std::vector<Texture>                  m_createdTextures;
    static std::map<const std::string, Texture>  m_loadedTextures;
public:
	// texture manager funcs
	//bool load(const std::string & path);
	//bool load(const std::vector<const std::string> & list);
	//bool existsTexture(const std::string & path) const;
	//void unload(std::string path);
	//void unload(std::vector<std::string> list);
	//void unloadAll();

	operator SDL_Renderer * ();
};


//static Renderer renderer;

