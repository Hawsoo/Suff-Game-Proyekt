#pragma once

#include "VController.h"
#include <SDL.h>

class VC_Keyboard : public VController
{
public:
	VC_Keyboard();
	void SetBindings(
		SDL_Keycode, SDL_Keycode, SDL_Keycode, SDL_Keycode,
		SDL_Keycode, SDL_Keycode, SDL_Keycode);
	void ProcessEvent(SDL_Event);
private:
	void InterpretKeycode(SDL_Keycode, bool);

	SDL_Keycode keyLeft, keyRight, keyUp, keyDown,
		keyStart, keyAttack, keyAction;
};

