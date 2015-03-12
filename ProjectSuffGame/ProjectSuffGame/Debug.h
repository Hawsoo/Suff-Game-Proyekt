#define DEBUG 1

#if DEBUG
	#define LOG(x)		std::cout << x << std::endl;
	#define EXIT		system("PAUSE"); return 0;
#else
	#define LOG(x)		;
	#define EXIT		return 0;
#endif