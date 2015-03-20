#pragma once

#include "VController.h"

class VC_Controller : public VController
{
public:
	VC_Controller(SDL_Joystick*);
	void SetController();
	void ProcessEvent(SDL_Event);
private:
	SDL_Joystick *joystick;

	// Bindings
	SDL_GameControllerAxis
		axisHorizontal, axisVertical;

	SDL_GameControllerButton
		buttonLeft, buttonRight, buttonUp, buttonDown,
		buttonStart, buttonAttack, buttonAction;
};

