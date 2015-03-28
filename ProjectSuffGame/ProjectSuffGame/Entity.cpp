#include "Entity.h"
#include "Ground.h"
#include "Room.h"

Entity::Entity(int x, int y, Room *room)
{
	this->x = x;
	this->y = y;
	this->room = room;
}

//--------------------------------------------------
// Moves the entity while checking for collision.
//--------------------------------------------------
void Entity::Move(int xoff, int yoff, int width, int height, double &hspeed, double &vspeed)
{
	// Move Hspeed
	for (int i = 0; i < std::ceil(std::abs(hspeed)); i++)
	{
		int moveAmount = std::copysign(1.0, hspeed);

		// Check if collision occurs ahead
		if (IsCollidingAll(Rect(x - xoff + moveAmount, y - yoff, width, height)))
		{
			// Stop
			hspeed = 0;
			break;
		}
		else
		{
			// Keep moving if no collision
			x += moveAmount;
		}
	}

	// Move Vspeed
	for (int i = 0; i < std::ceil(std::abs(vspeed)); i++)
	{
		int moveAmount = std::copysign(1.0, vspeed);

		// Check if collision occurs ahead
		if (IsCollidingAll(Rect(x - xoff, y - yoff + moveAmount, width, height)))
		{
			// Stop
			vspeed = 0;
			break;
		}
		else
		{
			// Keep moving if no collision
			y += moveAmount;
		}
	}
}

//--------------------------------------------------
// Tests collision among all ground objects.
//--------------------------------------------------
bool Entity::IsCollidingAll(Rect bounds)
{
	// Check for any collision
	for each (Ground *gnd in room->grounds)
	{
		if (gnd->IsColliding(bounds))
			return true;
	}

	// If none
	return false;
}