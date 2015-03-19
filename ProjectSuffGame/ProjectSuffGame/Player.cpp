#include "Player.h"
#include "Rect.h"

Player::Player(int x, int y, int inputPort) : Entity(x, y)
{
	this->inputPort = inputPort;
}

//--------------------------------------------------
// Gets collision and moves player.
//--------------------------------------------------
void Player::Update()
{

}

//--------------------------------------------------
// Renders the player.
//--------------------------------------------------
void Player::Render()
{
	glColor3f(0, 1, 1);
	Rect(x - 16, y, 32, 64).Render();
}