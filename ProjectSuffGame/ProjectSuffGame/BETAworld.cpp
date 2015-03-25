#include "BETAworld.h"
#include "Player.h"

BETAworld::BETAworld()
{
	entities.push_back(new Player(0, 0, 0));
}