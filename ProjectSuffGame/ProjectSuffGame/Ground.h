#pragma once

#include "Entity.h"
#include "Rect.h"

class Ground : public Entity
{
public:
	Rect bounds;

	Ground(Rect);

	//--------------------------------------------------
	// Tests collision.
	//--------------------------------------------------
	bool IsColliding(Rect other)
	{
		return bounds.IsColliding(other);
	}
};

