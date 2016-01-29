#pragma once

#include <SDL/SDL_render.h>
#include "Window.h"
#include"FlagsRenderer.h"
#include "Texture.h"

#include <vector>
#include <map>



class Renderer {
private:
	SDL_Renderer * m_sdlRenderer;
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
    std::vector<Texture> *                  m_textures;
    std::map<const std::string, Texture> *  m_texturesNamed;
public:
    void addTexture(Texture tex);
    void addTextureNamed(Texture tex,const std::string& name);
    bool existsTextureNamed(const std::string& name) const;
    Texture getTexture(int indx) const;
    Texture getTextureNamed(const std::string& name) const;
    void destroyTextures();
    void destroyTexturesNamed();
    void destroyAll();
};






















