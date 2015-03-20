#include "VC_Controller.h"
#include "Debug.h"

VC_Controller::VC_Controller(SDL_GameController *controller)
{
	this->controller = controller;
}

//--------------------------------------------------
// Processes the joystick events.
//--------------------------------------------------
void VC_Controller::ProcessEvent(SDL_Event e)
{
	switch (e.type)
	{
	case SDL_JOYAXISMOTION:
		break;

	case SDL_JOYBUTTONDOWN:
		break;

	case SDL_JOYBUTTONUP:
		break;
	}
}