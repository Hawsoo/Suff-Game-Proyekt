#pragma once

#include <SDL.h>
#include "Vector2f.h"

struct VController
{
	virtual void ProcessEvent(SDL_Event) = 0;

	Vector2f joyPos;		// UV coordinates of joystick position
	bool start;				// Menu button flag
	bool attack;			// Attack button flag
	bool action;			// Action button flag
};

