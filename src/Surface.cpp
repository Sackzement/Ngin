#include "../include/Surface.h"
#include "../include/Log.h"
#include <SDL/SDL_image.h>

std::vector<Surface>                 Surface:: m_createdSurfaces = std::vector<Surface>();
std::map<const std::string, Surface> Surface:: m_loadedSurfaces  = std::map<const std::string, Surface>();

void Surface::freeAllCreated() {

	auto it  = m_createdSurfaces.begin();
	auto end = m_createdSurfaces.end();

	for (; it != end; ++it)
		it->free();

	m_createdSurfaces.clear();

}
void Surface::freeAllLoaded() {

	auto it  = m_loadedSurfaces.begin();
	auto end = m_loadedSurfaces.end();

	for (; it != end; ++it)
		it->second.free();

	m_loadedSurfaces.clear();

}
void Surface::freeAll() {
	
	freeAllCreated();
	freeAllLoaded();

}
bool Surface::existsLoaded(const std::string & path) {

	try {
		const Surface & surf = m_loadedSurfaces.at(path);
		if (surf.exists())
			return true;
		else
			return false;
	}
	catch (const std::out_of_range ex) {
		return false;
	}

}






Surface:: operator SDL_Surface * () {
	return m_sdlSurface;
}


Surface::Surface()

	: m_sdlSurface(nullptr)
{}
bool Surface::create(int width, int height, int bitsperpixel,
	Uint32 rmask, Uint32 gmask, Uint32 bmask, Uint32 amask) {

	m_sdlSurface = SDL_CreateRGBSurface(0, width, height, bitsperpixel, 
		                                   rmask, gmask, bmask, amask);

	if (!m_sdlSurface) {

		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	m_createdSurfaces.push_back(*this);

	return true;
}
bool Surface::load(const std::string & file) {

	if (existsLoaded(file)) {
		*this = m_loadedSurfaces[file];
		return true;
	}

	m_sdlSurface = IMG_Load(file.c_str());

	if (!m_sdlSurface) {

		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	m_loadedSurfaces[file] = *this;

	return true;

}
bool Surface::save(const std::string & file) {

	return false;
}
bool Surface::exists() const {

	if (m_sdlSurface)
		return true;
	else
		return false;
}
void Surface::free() {

	SDL_FreeSurface(m_sdlSurface);
	m_sdlSurface = nullptr;
}