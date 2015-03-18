#pragma once

#include "Vector2f.h"

class Camera
{
	Vector2f pos;
public:
	Camera(int, int);
	Vector2f GetPosition();
};

