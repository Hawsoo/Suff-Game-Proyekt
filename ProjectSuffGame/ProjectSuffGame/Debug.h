#pragma once

#include <iostream>

#define DEBUG 1
#define PAUSE_WHEN_EXIT 0

#if DEBUG
	#define LOG(x)		std::cout << x << std::endl;
#else
	#define LOG(x)		;
#endif

#if PAUSE_WHEN_EXIT
	#define EXIT		system("PAUSE"); return 0;
#else
	#define EXIT		return 0;
#endif