#include "Camera.h"
#include "Display.h"

Camera::Camera(int x, int y)
{
	pos = Vector2f(x, y);
}

//--------------------------------------------------
// Gets the position of the camera relative to
// the projection matrix and aspect ratio thereof.
//--------------------------------------------------
Vector2f Camera::GetPosition()
{
	return Vector2f(
		pos.x - Display::viewHalfW,
		pos.y - Display::viewHalfH);
}
