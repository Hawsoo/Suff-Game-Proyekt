#include "BETAworld.h"
#include "Player.h"
#include "Gnd_Regular.h"

BETAworld::BETAworld()
{
	grounds.push_back(new Gnd_Regular(Rect(0, -80, 64, 8)));

	entities.push_back(new Player(0, 0, this, 0));
}