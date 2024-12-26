#include "GlobalVariables.h"
#include "SDL.h"

namespace Global {
	int windowWidth = 800;
	int windowHeight = 600;
	unsigned long long int frameCounter = 0;
	bool status = true;
	short frameDelay = 16;
	unsigned int TickTimer = 0;
	unsigned int LogicTimeEnd = 0;
	unsigned int RenderingTimeEnd = 0;
	unsigned char defaultDrawColor[3] = { 0,0,0 };
}