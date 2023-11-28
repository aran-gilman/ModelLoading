#include "Window.h"

#include <stdexcept>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Window::Window(int width, int height, const std::string& title)
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

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLEW");
	}

	glViewport(0, 0, width, height);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Display()
{
	while (!glfwWindowShouldClose(glfwWindow)) {
		glfwSwapBuffers(glfwWindow);
		glfwPollEvents();
	}
}
