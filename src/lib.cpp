

#include "../include/lib.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


Clib lib;


int Clib::init() {

	// INIT SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

		SDL_Log("Error:  Failed to init SDL  %s\n", SDL_GetError());
		return 0;
	}




	int ret = 1;
	// INIT SDL_img
	if (IMG_Init(IMG_INIT_PNG) == 0) {

		SDL_Log("Error:  Failed to init SDL_img  %s\n", SDL_GetError());
		ret |= 2;
	}
	// INIT SDL_ttf
	if (TTF_Init() == -1) {

		SDL_Log("Error:  Failed to init SDL_ttf  %s\n", SDL_GetError());
		ret |= 4;
	}
	return ret;

}




void Clib::quit() {
	SDL_Quit();
}