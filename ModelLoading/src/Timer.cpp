#include "Timer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Timer::Timer() :
	startTime(glfwGetTime())
{
}

TimeInSeconds Timer::GetElapsedTime()
{
	TimeInSeconds currentTime = glfwGetTime();
	TimeInSeconds diff = currentTime - startTime;
	startTime = currentTime;
	return diff;
}
