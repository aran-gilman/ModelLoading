#pragma once

using TimeInSeconds = double;

class Timer
{
public:
	Timer();
	TimeInSeconds GetElapsedTime();

private:
	TimeInSeconds startTime;
};

