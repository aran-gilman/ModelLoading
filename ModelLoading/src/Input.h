#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

enum class KeyAction : int
{
	Press = GLFW_PRESS,
	Release = GLFW_RELEASE,
	Repeat = GLFW_REPEAT,
};

