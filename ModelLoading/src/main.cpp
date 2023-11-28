#include <iostream>

#include <GL/glew.h>

#include "Window.h"

const char* vertexShaderSource = R"s(
#version 460 core
layout (location = 0) in vec3 inPos;

void main()
{
    gl_Position = vec4(inPos, 1.0);
})s";

const char* fragmentShaderSource = R"s(
#version 460 core
out vec4 FragColor;

void main()
{
    FragColor = (0.5f, 0.5f, 0.5f, 1.0f);
})s";

int main(int argc, char* argv[]) {
	Window window(800, 600, "Model Loading Test");

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);

	window.Display();
	return 0;
}