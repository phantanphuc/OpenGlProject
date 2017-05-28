#ifndef __FPSLIMITER_H__
#define __FPSLIMITER_H__

#include <ctime>
#include <windows.h>


class FPSLimiter {
public:
	FPSLimiter();
	~FPSLimiter();

	void waitForFrame();
	void setFPS(int pfps);

	void start();

private:

	int fps;
	int frame_len;

	clock_t frame_start_time = -1;

	
};
#endif
