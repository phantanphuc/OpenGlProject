#include "FPSLimiter.h"

FPSLimiter::FPSLimiter(){

}

FPSLimiter::~FPSLimiter(){

}

void FPSLimiter::waitForFrame()
{
	clock_t elapsed = std::clock() - frame_start_time;
	if (frame_len >= elapsed) {
		//frame_start_time += frame_len;
		Sleep(frame_len - elapsed);

		

		//return;
	}
	frame_start_time = std::clock();
	OutputDebugString("asasas");
}

void FPSLimiter::setFPS(int pfps)
{
	fps = pfps;
	frame_len = 1000 / fps;
}

void FPSLimiter::start()
{
	frame_start_time = std::clock();
}
