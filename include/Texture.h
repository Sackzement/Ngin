#pragma once
#include <SDL/SDL_render.h>
#include <string>



struct Texture
{

	SDL_Texture * p_texture;

	int width;
	int height;
	std::string name;
};




struct RenderFunc {
	virtual void render() = 0;
};


struct RenderTexture : public RenderFunc
{
	SDL_Renderer * p_renderer = nullptr;
	SDL_Texture  * p_texture  = nullptr;

	SDL_Rect     * p_srcrect  = nullptr;
	SDL_Rect       srcRect    = { 0,0,0,0 };

	SDL_Rect     * p_dstrect  = nullptr;
	SDL_Rect       dstRect    = { 0,0,0,0 };
	

	void render() override {
		SDL_RenderCopy(p_renderer,p_texture,p_srcrect,p_dstrect);
	}
};

struct RenderTextureEx : public RenderTexture
{

	double         angle        = 0.;

	SDL_Point   *  p_rotCenter  = nullptr;
	SDL_Rect       rotRect      = {0,0,0,0};

	SDL_RendererFlip flip       = SDL_FLIP_NONE;



	void render() override {
		SDL_RenderCopyEx(p_renderer, p_texture, p_srcrect, p_dstrect, angle, p_rotCenter, flip);
	}
};