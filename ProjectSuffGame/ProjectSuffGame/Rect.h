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
	// Draws a wireframe rectangle.
	//--------------------------------------------------
	void Render()
	{
		// Set to wireframe
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		// Draw quad
		glBegin(GL_QUADS);
		{
			glVertex2f(x,			y + height);
			glVertex2f(x + width,	y + height);
			glVertex2f(x + width,	y);
			glVertex2f(x,			y);
		}
		glEnd();

		// Revert to solid
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	//--------------------------------------------------
	// Checks collision between two rectangles.
	//--------------------------------------------------
	bool IsColliding(Rect other)
	{
		return (x < other.x + other.width && x + width > other.x &&
			y < other.y + other.height && y + height > other.y);
	}
};