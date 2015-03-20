#pragma once

#include "VController.h"
#include <SDL_gamecontroller.h>

class VC_Controller : public VController
{
public:
	VC_Controller(SDL_GameController*);
	void SetController();
	void ProcessEvent(SDL_Event);
private:
	SDL_GameController *controller;

	// Bindings
	SDL_GameControllerAxis
		axisHorizontal, axisVertical;

	SDL_GameControllerButton
		buttonLeft, buttonRight, buttonUp, buttonDown,
		buttonStart, buttonAttack, buttonAction;
};

