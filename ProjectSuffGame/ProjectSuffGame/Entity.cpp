#include "Entity.h"

Entity::Entity(int x, int y, Room *room)
{
	this->x = x;
	this->y = y;
	this->room = room;
}

//--------------------------------------------------
// Moves entity while checking for collision.
//--------------------------------------------------
void Entity::Move(double hspeed, double vspeed, int xoff, int yoff, int width, int height)
{
	int dir;
	Collision collision(false, Rect());

	// Move Hspeed
	x += hspeed;
	dir = std::copysign(1.0, hspeed);
	// TODO figger out the reason why this code doesn't work
	// If moving back is required
	if ((collision = IsCollidingAmong(xoff, yoff, width, height)).collided)
	{
		// Scoot to right
		if (dir < 0)
		{
			x = collision.bounds.x + collision.bounds.width + xoff;
		}
		// Scoot to left
		else
		{
			x = collision.bounds.x - width + xoff;
		}
	}

	// Move Vspeed
	y += vspeed;
	dir = std::copysign(1.0, vspeed);

	// If moving back is required
	if ((collision = IsCollidingAmong(xoff, yoff, width, height)).collided)
	{
		// Scoot up
		if (dir < 0)
		{
			y = collision.bounds.y + collision.bounds.height + yoff;
		}
		// Scoot down
		else
		{
			y = collision.bounds.y - height + yoff;
		}
	}
}

//--------------------------------------------------
// Checks if entity is colliding among all grounds.
// Then returns the bounds of the colliding ground.
// 
// xoff and yoff are positive numbers.
//--------------------------------------------------
Collision Entity::IsCollidingAmong(int xoff, int yoff, int width, int height)
{
	// Test for first collision
	for each (Ground *gnd in room->grounds)
	{
		if (gnd->IsColliding(Rect(x - xoff, y - yoff, width, height)))
			// Return a collision
			return Collision(true, gnd->bounds);
	}

	// Return false flag
	return Collision(false, Rect());
}