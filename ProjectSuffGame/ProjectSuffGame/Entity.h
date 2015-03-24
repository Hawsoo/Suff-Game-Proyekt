#pragma once

#include <vector>
#include "Ground.h"

class Entity
{
public:
	double x, y;
	
	Entity(int, int);

	virtual void Update() = 0;
	virtual void Render() = 0;
	void Move(double, double, int, int, int, int, std::vector<Ground*>&);

private:
	bool IsCollidingAmong(int, int, int, int, std::vector<Ground*>&);
};