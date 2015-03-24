#include "Entity.h"

Entity::Entity(int x, int y, std::vector<Ground*> *grounds)
{
	this->x = x;
	this->y = y;
	this->grounds = grounds;
}

//--------------------------------------------------
// Moves entity while checking for collision.
//--------------------------------------------------
void Entity::Move(double hspeed, double vspeed, int xoff, int yoff, int width, int height)
{
	int dir;
	Rect *collideBounds = nullptr;

	// Move Hspeed
	x += hspeed;
	dir = std::copysign(1.0, hspeed);

	// If moving back is required
	if ((collideBounds = IsCollidingAmong(xoff, yoff, width, height)) != nullptr)
	{
		// Scoot to right
		if (dir < 0)
		{
			x = collideBounds->x + collideBounds->width + xoff;
		}
		// Scoot to left
		else
		{
			x = collideBounds->x - width + xoff;
		}
	}

	// Move Vspeed
	y += vspeed;
	dir = std::copysign(1.0, vspeed);

	// If moving back is required
	if ((collideBounds = IsCollidingAmong(xoff, yoff, width, height)) != nullptr)
	{
		// Scoot up
		if (dir < 0)
		{
			y = collideBounds->y + collideBounds->height + yoff;
		}
		// Scoot down
		else
		{
			y = collideBounds->y - height + yoff;
		}
	}

	// Clean up
	delete collideBounds;
}

//--------------------------------------------------
// Checks if entity is colliding among all grounds.
// Then returns the bounds of the colliding ground.
// 
// xoff and yoff are positive numbers.
//--------------------------------------------------
Rect* Entity::IsCollidingAmong(int xoff, int yoff, int width, int height)
{
	// Test for first collision
	for each (Ground *gnd in *grounds)
	{
		if (gnd->IsColliding(Rect(x - xoff, y - yoff, width, height)))
			return &gnd->bounds;
	}

	// Return nothing
	return nullptr;
}