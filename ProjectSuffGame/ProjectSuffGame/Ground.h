#pragma once

#include "Entity.h"
#include "Rect.h"

class Ground
{
public:
	Rect bounds;

	Ground(Rect);
	virtual void Render() = 0;

	//--------------------------------------------------
	// Tests collision.
	//--------------------------------------------------
	bool IsColliding(Rect other)
	{
		return bounds.IsColliding(other);
	}
};

