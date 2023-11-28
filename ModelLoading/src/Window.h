#pragma once

#include <string>

class GLFWwindow;
class MeshRenderer;

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();

	void Display();

	void SetMesh(MeshRenderer* meshRenderer);

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

private:
	GLFWwindow* glfwWindow;
	MeshRenderer* renderedMesh;
};

