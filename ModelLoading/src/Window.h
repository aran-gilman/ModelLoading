#pragma once

#include <functional>
#include <string>

class GLFWwindow;

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();

	void Display();

	void SetRenderCallback(std::function<void()> renderCallback);

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

private:
	GLFWwindow* glfwWindow;
	std::function<void()> renderCallback;
};

