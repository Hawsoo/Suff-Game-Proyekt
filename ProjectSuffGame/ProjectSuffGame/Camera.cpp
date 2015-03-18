#include "Camera.h"
#include "Display.h"

Camera::Camera(int x, int y)
{
	pos = Vector2f(x, y);
}

Vector2f Camera::GetPosition()
{
	return Vector2f(
		pos.x - Display::viewHalfW,
		pos.y - Display::viewHalfH);
}
