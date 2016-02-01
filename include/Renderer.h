#pragma once

#include <SDL/SDL_render.h>
#include "Texture.h"
#include "Surface.h"




class Renderer {
	friend class Window;
private:
	SDL_Renderer* m_sdlRenderer;
public:
	Renderer();
	bool exists() const;
	void destroy();

	bool setTarget(Texture tex);
	bool setTargetDefault();
	bool setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	bool clear();
	bool copy(Texture tex,int x,int y,int w,int h);
	bool copyEx(Texture tex,int x,int y,int w,int h,double rot,int flip); // Flip flip

	Texture createTexture(Uint32 fmt, int acc, int w, int h);
	Texture createTexture(Surface surf);
};






















