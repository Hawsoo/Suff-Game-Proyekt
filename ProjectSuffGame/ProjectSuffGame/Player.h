#pragma once

#include "Entity.h"

class Player : public Entity
{
	int inputPort;
public:
	Player(int, int, int, Room*);

	int maxHspeed = 7, maxVspeed = 7;
	double hspeed = 0, vspeed = 0,
		friction = 0.5;

	void Update();
	void Render();
};

