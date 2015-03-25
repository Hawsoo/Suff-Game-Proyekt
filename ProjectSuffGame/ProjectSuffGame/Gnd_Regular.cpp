#include "Gnd_Regular.h"

Gnd_Regular::Gnd_Regular(Rect bounds) : Ground(bounds) {}

//--------------------------------------------------
// Renders a brown rectangle.
//--------------------------------------------------
void Gnd_Regular::Render()
{
	glColor3f(0.42f, 0.14f, 0.0f);
	bounds.Render();
}