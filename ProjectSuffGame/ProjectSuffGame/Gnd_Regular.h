#pragma once

#include "Ground.h"

class Gnd_Regular : public Ground
{
public:
	Gnd_Regular(Rect);
	void Render();
};