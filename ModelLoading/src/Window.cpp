#include "Window.h"

#include <stdexcept>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "MeshRenderer.h"

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
	while (!glfwWindowShouldClose(glfwWindow))
	{
		glClearColor(0.25f, 0.0f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (renderedMesh != nullptr)
		{
			renderedMesh->Render();
		}
		glfwSwapBuffers(glfwWindow);
		glfwPollEvents();
	}
}

void Window::SetMesh(MeshRenderer* meshRenderer)
{
	renderedMesh = meshRenderer;
}
