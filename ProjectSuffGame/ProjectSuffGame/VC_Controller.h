#pragma once

#include "VController.h"
#include <SDL_gamecontroller.h>

class VC_Controller : public VController
{
public:
	static int deadzone;

	VC_Controller(SDL_GameController*);
	void SetBindings(
		SDL_GameControllerAxis, SDL_GameControllerAxis,
		SDL_GameControllerButton, SDL_GameControllerButton, SDL_GameControllerButton, SDL_GameControllerButton,
		SDL_GameControllerButton, SDL_GameControllerButton, SDL_GameControllerButton);
	void ProcessEvent(SDL_Event);
private:
	void InterpretInput(Uint8, bool);

	SDL_GameController *controller;

	// Bindings
	SDL_GameControllerAxis
		axisHorizontal, axisVertical;

	SDL_GameControllerButton
		buttonLeft, buttonRight, buttonUp, buttonDown,
		buttonStart, buttonAttack, buttonAction;
};

