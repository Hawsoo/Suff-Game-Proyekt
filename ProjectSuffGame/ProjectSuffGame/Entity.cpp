#include "Entity.h"

Entity::Entity(int x, int y)
{
	this->x = x;
	this->y = y;
}

//--------------------------------------------------
// Moves entity while checking for collision.
//--------------------------------------------------
void Entity::Move(double hspeed, double vspeed, int xoff, int yoff, int width, int height, std::vector<Ground*> &grounds)
{
	int dir;

	// Move Hspeed
	x += hspeed;
	dir = std::copysign(1.0, hspeed);

	// If moving back is required
	if (IsCollidingAmong(xoff, yoff, width, height, grounds))
	{
		// Scoot to right
		if (dir < 0)
		{

		}
		// Scoot to left
		else
		{

		}
	}

	// Move Vspeed
	y += vspeed;
	dir = std::copysign(1.0, vspeed);

	// If moving back is required
	if (IsCollidingAmong(xoff, yoff, width, height, grounds))
	{
		// Scoot up
		if (dir < 0)
		{

		}
		// Scoot down
		else
		{

		}
	}
}

//--------------------------------------------------
// Checks if entity is colliding among all grounds.
//--------------------------------------------------
bool Entity::IsCollidingAmong(int xoff, int yoff, int width, int height, std::vector<Ground*> &grounds)
{
	bool collided = false;
	for each (Ground *gnd in grounds)
	{
		/*if (gnd->bounds.IsColliding(Rect(x + xoff, y + yoff, width, height))*/
		{
			collided = true;
			break;
		}
	}
	return collided;
}