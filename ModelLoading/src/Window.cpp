#include "Window.h"

#include <stdexcept>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "MeshRenderer.h"
#include "Timer.h"

namespace
{
	void EmptyPerFrameCallback(double) {}
	void EmptyKeyboardCallback(KeyToken, int, KeyAction, int) {}

	void HandleKeyboardInput(GLFWwindow* window, int keyToken, int scancode, int action, int mods)
	{
		Window* user = static_cast<Window*>(glfwGetWindowUserPointer(window));
		user->SendKeyboardEvent(static_cast<KeyToken>(keyToken), scancode, static_cast<KeyAction>(action), mods);
	}
}

Window::Window(int width, int height, const std::string& title) :
	renderCallback(EmptyPerFrameCallback),
	updateCallback(EmptyPerFrameCallback),
	keyboardCallback(EmptyKeyboardCallback)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (glfwWindow == nullptr)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(glfwWindow);
	glfwSetWindowUserPointer(glfwWindow, this);
	glfwSetKeyCallback(glfwWindow, HandleKeyboardInput);

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLEW");
	}

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Display()
{
	Timer timer;
	while (!glfwWindowShouldClose(glfwWindow))
	{
		double diff = timer.GetElapsedTime();
		updateCallback(diff);

		glClearColor(0.25f, 0.0f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderCallback(diff);
		glfwSwapBuffers(glfwWindow);

		glfwPollEvents();
	}
}

void Window::SetRenderCallback(std::function<void(double)> renderCallback)
{
	this->renderCallback = renderCallback;
}

void Window::SetUpdateCallback(std::function<void(double)> updateCallback)
{
	this->updateCallback = updateCallback;
}

void Window::SetKeyboardCallback(std::function<void(KeyToken, int, KeyAction, int)> keyboardCallback)
{
	this->keyboardCallback = keyboardCallback;
}

void Window::SendKeyboardEvent(KeyToken keyToken, int scancode, KeyAction action, int mods)
{
	keyboardCallback(keyToken, scancode, action, mods);
}
