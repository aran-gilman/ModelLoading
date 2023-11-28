#pragma once

#include <string>

class GLFWwindow;

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();

	void Display();

private:
	GLFWwindow* glfwWindow;
};

