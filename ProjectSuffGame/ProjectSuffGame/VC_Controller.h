#pragma once

#include "VController.h"

class VC_Controller : public VController
{
public:
	VC_Controller();
	void SetController();
	void ProcessEvent(SDL_Keycode);
private:
	// Bindings
	SDL_GameControllerAxis
		axisHorizontal, axisVertical;

	SDL_GameControllerButton
		buttonLeft, buttonRight, buttonUp, buttonDown,
		buttonStart, buttonAttack, buttonAction;
};

