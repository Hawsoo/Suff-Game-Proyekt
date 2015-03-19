#pragma once

#include "Entity.h"

class Player : public Entity
{
	int inputPort;
public:
	Player(int, int, int);

	void Update();
	void Render();
};

