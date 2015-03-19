#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include "Debug.h"
#include "Display.h"
#include "InputEvents.h"
#include "VC_Keyboard.h"

//--------------------------------------------------
// Creates the Window for the application.
//--------------------------------------------------
void SetupWindow()
{
	// Init
	SDL_Init(SDL_INIT_EVERYTHING);

	// Setup Window and Context
	LOG("::Initializing SDL2 and OpenGL...");

	Display::window = SDL_CreateWindow("Project Alchemy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Display::width, Display::height, SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	Display::context = SDL_GL_CreateContext(Display::window);

	// Setup initial OpenGL
	Display::SetupGLDisplay();

	SDL_GL_SetSwapInterval(1);
	SDL_ShowCursor(0);
	SDL_ShowWindow(Display::window);
}

//--------------------------------------------------
// Tears down everything.
//--------------------------------------------------
void Unload()
{
	SDL_DestroyWindow(Display::window);
	SDL_GL_DeleteContext(Display::context);
	SDL_Quit();
}

//--------------------------------------------------
// Sets up and manages program.
//--------------------------------------------------
int main(int argc, char **argv)
{
	LOG("============ Program Started ===========" << std::endl);
	
	// Setup OpenGL
	SetupWindow();

	// BETA!!!
	InputEvents::inputs.push_back(new VC_Keyboard());

	// Game Loop
	while (InputEvents::running)
	{
		// Get input
		SDL_PumpEvents();
		InputEvents::Process();

		// Update
		
		// Render
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		{
			// Adjust to main camera
			Vector2f pos = Display::mainCam.GetPosition();
			glTranslatef(-pos.x, -pos.y, 0);

			// BETA: red rect. for demonstrationing
			glColor3f(1, 0, 0);
			glBegin(GL_QUADS);
			{
				glVertex2f(0, Display::height / 2);
				glVertex2f(Display::width / 2, Display::height / 2);
				glVertex2f(Display::width / 2, 0);
				glVertex2f(0, 0);
			}
			glEnd();
		}
		glPopMatrix();

		SDL_GL_SwapWindow(Display::window);
	}

	// Clean up
	Unload();

	// Close program
	LOG("");
	EXIT;
}