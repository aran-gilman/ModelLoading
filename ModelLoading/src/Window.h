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
	void SetKeyboardCallback(std::function<void(int, int, int, int)> keyboardCallback);

	void SendKeyboardEvent(int keyToken, int scancode, int action, int mods);

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

private:
	GLFWwindow* glfwWindow;
	std::function<void()> renderCallback;
	std::function<void(int, int, int, int)> keyboardCallback;
};

