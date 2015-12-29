#include "../include/textures.h"
#include <SDL/SDL_surface.h>
#include <SDL/SDL_image.h>
#include "sdlRenderer.h">
#include <algorithm>



map<cchar*, Texture> Ctextures::list = map<cchar*, Texture>();


bool  Ctextures::loadTexture(cchar * fileName) {
	// get texture pos from name  in list
	Texture& tex = list[fileName];
	// check if already exists
	if (tex.texturePtr != nullptr) {
		SDL_Log("Error:  Texture already exists  \"%s\" ", fileName);
		return false;
	}
	// load file into Surface
	SDL_Surface* surf = IMG_Load(fileName);
	if (!surf) {
		SDL_Log("Error:  Failed to load file \"%s\"  %s", fileName, SDL_GetError());
		return false;
	}

	bool success = false;
	// create texture from surface
	SDL_Texture* sdlTex = SDL_CreateTextureFromSurface(sdlRenderer, surf);
	if (!sdlTex)
		SDL_Log("Error:  Failed to create Texture from Surface image  \"%s\"  %s", fileName, SDL_GetError());
	else {
		// assign texture data to texture in list
			tex.texturePtr = sdlTex;
			tex.name = fileName;
			tex.width = surf->w;
			tex.height = surf->h;
			success = true;
	}
	// delete loaded surface
	SDL_FreeSurface(surf);
	return success;
		
}



void  Ctextures::unloadAllTextures() {

	// traverses list, deletes every texture
	// deletes list
	auto it = list.begin();
	auto end = list.end();
	for (; it != end; ++it) {
		if ((*it).second.texturePtr != nullptr)
			SDL_DestroyTexture( (SDL_Texture*)(*it).second.texturePtr);
	}
	list.clear();

}



/*
void    Engine::loadResources() {

	for (auto it = resToLoad.begin(); it != resToLoad.end(); ++it) {

		size_t pointPos = (*it).find('.');
		if (pointPos == -1)
			std::cout << *it << "  has no file ending \".file\"" << std::endl;
		else {

			std::string fileEnding = (*it).substr(pointPos + 1);

			if (fileEnding == "ttf") {

				TTF_Font* font = TTF_OpenFont((*it).c_str(), 28);
				if (!font)
					printf("Error:  Failed to load font \"%s\"  %s\n", (*it).c_str(), SDL_GetError());
				else
					fonts[*it] = font;
			}
			else if ((fileEnding == "png")
				|| (fileEnding == "jpg")) {

				SDL_Surface* surf = IMG_Load((*it).c_str());
				if (!surf)
					printf("Error:  Failed to load image \"%s\"  %s\n", (*it).c_str(), SDL_GetError());
				else {
					SDL_Texture* sdlTex = SDL_CreateTextureFromSurface(window, surf);
					if (!sdlTex)
						printf("Error:  Failed to create Texture from Surface image  \"%s\"  %s\n", (*it).c_str(), SDL_GetError());
					else
						textures[*it] = new Texture(sdlTex, surf->w, surf->h);

					SDL_FreeSurface(surf);
				}
			}
			else
				std::cout << "No matching file ending for  " << fileEnding << std::endl;
		}
	}

}*/