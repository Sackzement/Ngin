#include "../include/FlagsInit.h"

#include <SDL/SDL.h>

const Uint32 Flags::Init::
	timer           = SDL_INIT_TIMER,
	audio           = SDL_INIT_AUDIO,
	video           = SDL_INIT_VIDEO,
	joystick        = SDL_INIT_JOYSTICK,
	haptic          = SDL_INIT_HAPTIC,
	gamecontroller  = SDL_INIT_GAMECONTROLLER,
	events          = SDL_INIT_EVENTS,
	everything      = SDL_INIT_EVERYTHING;

