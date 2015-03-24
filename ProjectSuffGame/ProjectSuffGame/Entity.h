#pragma once

#include <vector>
#include "Ground.h"

class Entity
{
public:
	double x, y;
	std::vector<Ground*> *grounds;
	
	Entity(int, int, std::vector<Ground*>*);

	virtual void Update() = 0;
	virtual void Render() = 0;

	void Move(double, double, int, int, int, int);
private:
	Rect IsCollidingAmong(int, int, int, int);
};