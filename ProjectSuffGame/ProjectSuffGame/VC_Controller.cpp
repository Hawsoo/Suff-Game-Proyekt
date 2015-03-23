#include "VC_Controller.h"
#include "Debug.h"

int VC_Controller::deadzone = 12000;

VC_Controller::VC_Controller(SDL_GameController *controller)
{
	this->controller = controller;

	// Set bindings
	axisHorizontal = SDL_CONTROLLER_AXIS_LEFTX;
	axisVertical = SDL_CONTROLLER_AXIS_LEFTY;

	buttonLeft = SDL_CONTROLLER_BUTTON_DPAD_LEFT;
	buttonRight = SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
	buttonUp = SDL_CONTROLLER_BUTTON_DPAD_UP;
	buttonDown = SDL_CONTROLLER_BUTTON_DPAD_DOWN;

	buttonStart = SDL_CONTROLLER_BUTTON_START;
	buttonAttack = SDL_CONTROLLER_BUTTON_X;
	buttonAction = SDL_CONTROLLER_BUTTON_A;
}

//--------------------------------------------------
// Sets the controller bindings for the VC.
//--------------------------------------------------
void VC_Controller::SetBindings(
	SDL_GameControllerAxis horizontal, SDL_GameControllerAxis vertical,
	SDL_GameControllerButton left, SDL_GameControllerButton right, SDL_GameControllerButton up, SDL_GameControllerButton down,
	SDL_GameControllerButton start, SDL_GameControllerButton attack, SDL_GameControllerButton action)
{
	// Set bindings
	axisHorizontal = horizontal;
	axisVertical = vertical;

	buttonLeft = left;
	buttonRight = right;
	buttonUp = up;
	buttonDown = down;

	buttonStart = start;
	buttonAttack = attack;
	buttonAction = action;
}

//--------------------------------------------------
// Processes the joystick events.
//--------------------------------------------------
void VC_Controller::ProcessEvent(SDL_Event e)
{
	switch (e.type)
	{
	case SDL_CONTROLLERAXISMOTION:
		// Check which axis
		if (e.caxis.axis == axisHorizontal)
		{
			// Update value
			if (e.caxis.value < -deadzone)
				joyPos.x = -1;
			else if (e.caxis.value > deadzone)
				joyPos.x = 1;
			else
				joyPos.x = 0;
		}
		else if (e.caxis.axis == axisVertical)
		{
			// Update value
			if (e.caxis.value < -deadzone)
				joyPos.y = 1;
			else if (e.caxis.value > deadzone)
				joyPos.y = -1;
			else
				joyPos.y = 0;
		}
		break;

	case SDL_CONTROLLERBUTTONDOWN:
		// Interpret the input
		InterpretInput(e.cbutton.button, true);
		break;

	case SDL_CONTROLLERBUTTONUP:
		// Interpret the input
		InterpretInput(e.cbutton.button, false);
		break;
	}
}

//--------------------------------------------------
// Interprets the key input from the processing
// statement.
//--------------------------------------------------
void VC_Controller::InterpretInput(Uint8 code, bool down)
{
	// Interpret button event
	if (code == buttonLeft) joyPos.x = -down;
	else if (code == buttonRight) joyPos.x = down;
	else if (code == buttonUp) joyPos.y = down;
	else if (code == buttonDown) joyPos.y = -down;

	else if (code == buttonStart) start = down;
	else if (code == buttonAttack) attack = down;
	else if (code == buttonAction) action = down;
}
