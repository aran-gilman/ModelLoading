#include "Timer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Timer::Timer() :
	startTime(glfwGetTime())
{
}

TimeInSeconds Timer::GetElapsedTime() const
{
	return glfwGetTime() - startTime;
}

void Timer::Reset()
{
	startTime = 0.0f;
}
