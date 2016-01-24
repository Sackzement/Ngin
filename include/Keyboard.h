#pragma once
#include <SDL/SDL_keyboard.h>
#include <cstring>



struct Keyboard
{
	bool  down      [SDL_NUM_SCANCODES], 
	      down_once [SDL_NUM_SCANCODES],
	      up_once   [SDL_NUM_SCANCODES];

	void reset_onces() {
		memset(down_once, false, SDL_NUM_SCANCODES);
		memset(up_once, false, SDL_NUM_SCANCODES);
	}
	void input_keydown(SDL_Scancode scancode) {

		down_once[scancode] = true;
		down[scancode] = true;
	}
	void input_keyup(SDL_Scancode scancode) {
		up_once[scancode] = true;
		down[scancode] = false;
	}
};