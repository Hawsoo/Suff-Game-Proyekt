#pragma once

#include <SDL_opengl.h>

struct Rect
{
	int x, y, width, height;

	Rect()
	{
		x = 0;
		y = 0;
		width = 0;
		height = 0;
	}

	Rect(int x, int y, int width, int height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	//--------------------------------------------------
	// Draws a solid rectangle.
	//--------------------------------------------------
	void Render()
	{
		glBegin(GL_QUADS);
		{
			glVertex2f(x,			y + height);
			glVertex2f(x + width,	y + height);
			glVertex2f(x + width,	y);
			glVertex2f(x,			y);
		}
		glEnd();
	}
};