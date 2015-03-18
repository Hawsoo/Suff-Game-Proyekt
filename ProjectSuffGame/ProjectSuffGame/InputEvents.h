#pragma once

#include <SDL.h>

class InputEvents
{
public:
	static bool running;
	static void Process();

private:
	static SDL_Event e;
};

