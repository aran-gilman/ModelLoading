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

private:
	GLFWwindow* glfwWindow;
	MeshRenderer* renderedMesh;
};

