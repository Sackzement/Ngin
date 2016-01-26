#pragma once
#include <SDL/SDL_surface.h>
#include <string>
#include <vector>
#include <map>

struct Surface {

	operator SDL_Surface * ();
private:
	SDL_Surface * m_sdlSurface;
public:
	Surface();
	bool create(int width,int height,int bitsperpixel,
		Uint32 rmask, Uint32 gmask, Uint32 bmask,Uint32 amask);
	bool load(const std::string & file);
	bool save(const std::string & file);
	bool exists() const;
	void free();

private:
	static std::vector<Surface>                 m_createdSurfaces;
	static std::map<const std::string,Surface>  m_loadedSurfaces;
public:
	static Surface getLoaded();
	static bool existsLoaded(const std::string & path);
	static void freeAllCreated();
	static void freeAllLoaded();
public:
	static void freeAll();
};