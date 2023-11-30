#pragma once

using TimeInSeconds = double;

class Timer
{
public:
	Timer();

	TimeInSeconds GetElapsedTime() const;
	void Reset();

private:
	TimeInSeconds startTime;
};

