#include "../include/FlagsRenderer.h"
#include <SDL/SDL_render.h>



namespace Flags {

	namespace Renderer {

		const Uint32
			software     = SDL_RENDERER_SOFTWARE,
			accelerated  = SDL_RENDERER_ACCELERATED,
			vsync        = SDL_RENDERER_PRESENTVSYNC,
			texture      = SDL_RENDERER_TARGETTEXTURE;

	}

}