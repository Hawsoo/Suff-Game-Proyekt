#pragma once

#include "Entity.h"

class Player : public Entity
{
	int inputPort;
public:
	Player(int, int, int, std::vector<Ground*>*);

	int maxHspeed = 7, maxVspeed = 7;
	double hspeed = 0, vspeed = 0,
		friction = 0.5;

	void Update();
	void Render();
};

