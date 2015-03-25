#pragma once

#include <vector>
#include "Ground.h"
#include "Room.h"

struct Collision
{
	bool collided;
	Rect bounds;
	
	Collision(bool collided, Rect bounds)
	{
		this->collided = collided;
		this->bounds = bounds;
	}
};

class Entity
{
public:
	double x, y;
	Room *room;
	
	Entity(int, int, Room*);

	virtual void Update() = 0;
	virtual void Render() = 0;

	void Move(double, double, int, int, int, int);
private:
	Collision IsCollidingAmong(int, int, int, int);
};