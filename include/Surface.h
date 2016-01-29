#pragma once
#include <SDL/SDL_surface.h>
#include <string>
#include <vector>
#include <map>



struct Surface {
private:
	SDL_Surface * m_sdlSurface;
public:
	     Surface();
	bool create(int w,int h,int bpp,Uint32 rmask,Uint32 gmask,Uint32 bmask,Uint32 amask);
	bool load(const std::string & file);
	bool save(const std::string & file) const;
	bool exists() const;
	void free();

private:
	static std::vector<Surface> *                 m_surfaces;
	static std::map<const std::string,Surface> *  m_surfacesNamed;
public:
    static void addSurface(Surface surf);
    static void addSurfaceNamed(Surface surf,const std::string& name);
    static bool existsSurfaceNamed(const std::string& name);
    static Surface getSurface(int indx);
    static Surface getSurfaceNamed(const std::string& name);
    static void freeSurfaces();
    static void freeSurfacesNamed();
    static void freeAll();
};