#include "VC_Controller.h"

VC_Controller::VC_Controller(SDL_Joystick *joystick)
{
	this->joystick = joystick;
}

void VC_Controller::ProcessEvent(SDL_Event e)
{
	switch (e.type)
	{
	case SDL_JOYAXISMOTION:
	{
		break;
	}

	case SDL_JOYHATMOTION:
	{
		break;
	}

	case SDL_JOYBUTTONDOWN:
	{
		break;
	}
	}
}