#include "VC_Keyboard.h"
#include <SDL.h>
#include "Debug.h"

VC_Keyboard::VC_Keyboard()
{
	keyLeft = SDLK_LEFT;
	keyRight = SDLK_RIGHT;
	keyUp = SDLK_UP;
	keyDown = SDLK_DOWN;

	keyStart = SDLK_RETURN;
	keyAttack = SDLK_c;
	keyAction = SDLK_x;
}

//--------------------------------------------------
// Sets the keybindings for the VC.
//--------------------------------------------------
void VC_Keyboard::SetBindings(
	SDL_Keycode left, SDL_Keycode right, SDL_Keycode up, SDL_Keycode down,
	SDL_Keycode start, SDL_Keycode attack, SDL_Keycode action)
{
	keyLeft = left;
	keyRight = right;
	keyUp = up;
	keyDown = down;

	keyStart = start;
	keyAttack = attack;
	keyAction = action;
}

//--------------------------------------------------
// Processes any keyboard input.
//--------------------------------------------------
void VC_Keyboard::ProcessEvent(SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
	{
		InterpretKeycode(e.key.keysym.sym, true);
		break;
	}

	case SDL_KEYUP:
	{
		InterpretKeycode(e.key.keysym.sym, false);
		break;
	}
	}
}

//--------------------------------------------------
// Interprets the key input from the processing
// statement.
//--------------------------------------------------
void VC_Keyboard::InterpretKeycode(SDL_Keycode code, bool down)
{
	int mult = 1;
	if (!down) mult = 0;

	// Interpret key event
	if (code == keyLeft) arrowLeft = down;
	else if (code == keyRight) arrowRight = down;
	else if (code == keyUp) arrowUp = down;
	else if (code == keyDown) arrowDown = down;

	else if (code == keyStart) start = down;
	else if (code == keyAttack) attack = down;
	else if (code == keyAction) action = down;
	
	// Update joystick position
	if (arrowLeft && !arrowRight) joyPos.x = -1;
	else if (arrowRight && !arrowLeft) joyPos.x = 1;
	else joyPos.x = 0;

	if (arrowUp && !arrowDown) joyPos.y = 1;
	else if (arrowDown && !arrowUp) joyPos.y = -1;
	else joyPos.y = 0;
}