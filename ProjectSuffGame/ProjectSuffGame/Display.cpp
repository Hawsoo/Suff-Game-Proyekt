#include "Display.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include "BETAworld.h"
#include "Debug.h"

SDL_Window *Display::window;
SDL_GLContext Display::context;
Camera Display::mainCam = Camera(0, 0);
Room *Display::room = new BETAworld();		// TODO: create a beta room, then set it here

int Display::viewHalfW, Display::viewHalfH;
const int Display::width = 1024;
const int Display::height = 576;

//--------------------------------------------------
// Sets up a simple display within the GL context.
//--------------------------------------------------
void Display::SetupGLDisplay()
{
	// Get dimensions
	int displayW, displayH;
	SDL_GetWindowSize(window, &displayW, &displayH);

	float heightRatio = height / (float)displayH;
	int viewWidth = (int)(displayW * heightRatio);
	int viewHeight = (int)(displayH * heightRatio);

	// Setup matrix projection
	glViewport(0, 0, displayW, displayH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, viewWidth, 0, viewHeight, -1, 1);
	glMatrixMode(GL_MODELVIEW);

	// Update variables
	viewHalfW = viewWidth / 2;
	viewHalfH = viewHeight / 2;

	// Log context size
	LOG("::Context Size set to " << displayW << "x" << displayH);
}
