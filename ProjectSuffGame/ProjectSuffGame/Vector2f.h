#pragma once

struct Vector2f
{
	float x, y;

	Vector2f()
	{
		this->x = 0;
		this->y = 0;
	}

	Vector2f(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};