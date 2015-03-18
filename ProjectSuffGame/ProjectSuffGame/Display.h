#pragma once

#include <SDL.h>
#include <SDL_opengl.h>
#include "Camera.h"

class Display
{
public:
	static SDL_Window *window;
	static SDL_GLContext context;
	static Camera mainCam;

	static int viewHalfW, viewHalfH;
	static const int width, height;

	static void SetupGLDisplay();
};

