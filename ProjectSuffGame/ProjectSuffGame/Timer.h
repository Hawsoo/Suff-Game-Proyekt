#pragma once

#include <SDL.h>
#include <algorithm>

class Timer
{
public:
	Timer()
	{
		starttime = 0;
		pausedtime = 0;

		started = false;
		paused = false;
	}

	//--------------------------------------------------
	// Starts the timer (does not unpause).
	//--------------------------------------------------
	void Start()
	{
		started = true;
		paused = false;

		starttime = SDL_GetTicks();
		pausedtime = 0;
	}

	//--------------------------------------------------
	// Pauses the timer.
	//--------------------------------------------------
	void Pause()
	{
		if (started && !paused)
		{
			// Pause timer & record time
			paused = true;
			pausedtime = SDL_GetTicks() - starttime;
		}
	}

	//--------------------------------------------------
	// Unpauses the timer.
	//--------------------------------------------------
	void Unpause()
	{
		if (started && paused)
		{
			// Unpause timer & recalibrate timer
			paused = false;
			starttime = SDL_GetTicks() - pausedtime;
		}
	}

	//--------------------------------------------------
	// Gets the (pasteurized) time.
	//--------------------------------------------------
	Uint32 GetTime()
	{
		Uint32 pasteurizedtime = 0;

		// Get correct time value depending on circumstances
		if (started)
		{
			if (paused)
			{
				pasteurizedtime = pausedtime;
			}
			else
			{
				pasteurizedtime = SDL_GetTicks() - starttime;
			}
		}

		// Clamp to zero if SDL_GetTicks() loops
		return std::max(pasteurizedtime, (Uint32)0);
	}

	//--------------------------------------------------
	// Gets if timer has started.
	//--------------------------------------------------
	bool isStarted()
	{
		return started;
	}

	//--------------------------------------------------
	// Gets if timer has paused.
	//--------------------------------------------------
	bool isPaused()
	{
		return paused;
	}

private:
	// Timing fields
	Uint32 starttime;
	Uint32 pausedtime;

	bool started;
	bool paused;
};