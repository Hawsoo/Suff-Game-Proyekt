#include "Player.h"
#include "Rect.h"
#include "InputEvents.h"
#include "Debug.h"
#include <algorithm>

Player::Player(int x, int y, Room *room, int inputPort) : Entity(x, y, room)
{
	this->inputPort = inputPort;
}

//--------------------------------------------------
// Gets collision and moves player.
//--------------------------------------------------
void Player::Update()
{
	Vector2f joyPos = InputEvents::inputs[inputPort]->joyPos;
	hspeed += joyPos.x / 2;
	vspeed += joyPos.y / 2;

	// Limit hspeed
	hspeed = std::max(std::min(hspeed, (double)maxHspeed), (double)-maxHspeed);
	vspeed = std::max(std::min(vspeed, (double)maxVspeed), (double)-maxVspeed);

	// Apply friction
	if (joyPos.x == 0)
	{
		if (hspeed > 0)
		{
			hspeed -= friction;
			if (hspeed < 0) hspeed = 0;
		}
		else if (hspeed < 0)
		{
			hspeed += friction;
			if (hspeed > 0) hspeed = 0;
		}
	}

	if (joyPos.y == 0)
	{
		if (vspeed > 0)
		{
			vspeed -= friction;
			if (vspeed < 0) vspeed = 0;
		}
		else if (vspeed < 0)
		{
			vspeed += friction;
			if (vspeed > 0) vspeed = 0;
		}
	}

	// Apply movement
	Move(16, 0, 32, 64, hspeed, vspeed);

	//LOG(hspeed);
}

//--------------------------------------------------
// Renders the player.
//--------------------------------------------------
void Player::Render()
{
	glColor3f(0, 1, 1);
	Rect(x - 16, y, 32, 64).Render();
}