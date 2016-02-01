#pragma once
#include <SDL/SDL_surface.h>
#include <string>
#include <vector>
#include <map>



struct Surface {
private:
	SDL_Surface * m_sdlSurface;
public:
	bool create(int w, int h, int bpp, Uint32 rmask, Uint32 gmask, Uint32 bmask, Uint32 amask);
	bool load(const std::string& filepath);
	bool save(const std::string& filepath) const;
	bool exists() const;
	void free();

};