#include <iostream>
#include <memory>
#include <stdexcept>

#include "MeshData.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Window.h"

const char* vertexShaderSource = R"s(
#version 460 core
layout (location = 0) in vec3 inPos;

void main()
{
    gl_Position = vec4(inPos, 1.0f);
})s";

const char* fragmentShaderSource = R"s(
#version 460 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(0.5f, 0.5f, 0.5f, 1.0f);
})s";

int main(int argc, char* argv[])
{
	try
	{
		Window window(800, 600, "Model Loading Test");

		VertexShader vertexShader(vertexShaderSource);
		FragmentShader fragmentShader(fragmentShaderSource);
		std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);

		MeshRenderer meshRenderer(CreateTriangle(), shaderProgram);

		window.Display();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}