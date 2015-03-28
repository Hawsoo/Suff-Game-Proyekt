#pragma once

#include "Vector2f.h"
#include "Rect.h"
class Room;

class Entity
{
public:
	double x, y;
	Room *room;
	
	Entity(int, int, Room*);

	void Move(int, int, int, int, double&, double&);

	virtual void Update() = 0;
	virtual void Render() = 0;

private:
	bool IsCollidingAll(Rect);
};

