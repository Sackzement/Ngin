#include "../include/FlagsWindow.h"
#include <SDL/SDL_video.h>



namespace Flags {

	namespace Window {
	
		const Uint32
			fullscreen         = SDL_WINDOW_FULLSCREEN,
			opengl             = SDL_WINDOW_OPENGL,
			shown              = SDL_WINDOW_SHOWN,
			hidden             = SDL_WINDOW_HIDDEN,
			borderless         = SDL_WINDOW_BORDERLESS,
			resizable          = SDL_WINDOW_RESIZABLE,
			minimized          = SDL_WINDOW_MINIMIZED,
			maximized          = SDL_WINDOW_MAXIMIZED,
			inputGrabbed       = SDL_WINDOW_INPUT_GRABBED,
			inputFocus         = SDL_WINDOW_INPUT_FOCUS,
			mouseFocus         = SDL_WINDOW_MOUSE_FOCUS,
			fullscreenDesktop  = SDL_WINDOW_FULLSCREEN_DESKTOP,
			foreign            = SDL_WINDOW_FOREIGN,
			allowHighDPI       = SDL_WINDOW_ALLOW_HIGHDPI,
			mouseCapture       = SDL_WINDOW_MOUSE_CAPTURE;

	}

}