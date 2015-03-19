#pragma once

class Entity
{
public:
	double x, y;
	
	Entity(int, int);

	virtual void Update() = 0;
	virtual void Render() = 0;
};

