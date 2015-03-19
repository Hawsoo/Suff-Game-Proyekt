#pragma once

#include <vector>
#include "Entity.h"

class Room
{
public:
	std::vector<Entity*> entities;
	std::vector<Ground*> grounds;

	Room();

	void Update();
	void Render();
};

