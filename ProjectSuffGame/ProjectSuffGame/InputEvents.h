#pragma once

#include <SDL.h>
#include <vector>
#include "VController.h"

class InputEvents
{
public:
	static bool running;
	static void Process();

	static std::vector<VController*> inputs;
private:
	static SDL_Event e;
};

