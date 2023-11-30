#pragma once

#include <functional>
#include <string>

#include "InputEnums.h"

struct GLFWwindow;

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();

	void Display();

	void SetRenderCallback(std::function<void()> renderCallback);
	void SetKeyboardCallback(std::function<void(int, int, KeyAction, int)> keyboardCallback);

	void SendKeyboardEvent(int keyToken, int scancode, KeyAction action, int mods);

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

private:
	GLFWwindow* glfwWindow;
	std::function<void()> renderCallback;
	std::function<void(int, int, KeyAction, int)> keyboardCallback;
};

