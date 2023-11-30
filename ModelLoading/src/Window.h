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
	void SetKeyboardCallback(std::function<void(KeyToken, int, KeyAction, int)> keyboardCallback);

	void SendKeyboardEvent(KeyToken keyToken, int scancode, KeyAction action, int mods);

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

private:
	GLFWwindow* glfwWindow;
	std::function<void()> renderCallback;
	std::function<void(KeyToken, int, KeyAction, int)> keyboardCallback;
};

