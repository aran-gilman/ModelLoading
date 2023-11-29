#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"
#include "MeshData.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Window.h"

const char* vertexShaderSource = R"s(
#version 460 core
layout (location = 0) in vec3 inPos;

layout (std140, binding = 0) uniform Camera
{
    mat4 view;
    mat4 projection;
    vec4 position;
} camera;

void main()
{
    gl_Position = camera.projection * camera.view * vec4(inPos, 1.0f);
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

		glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

		Camera camera({
			glm::lookAt(position, position + front, up),
			glm::perspective(glm::radians(45.0f), 800.0f / 600, 0.1f, 100.0f),
			glm::vec4(position, 0.0f)
		});

		VertexShader vertexShader(vertexShaderSource);
		FragmentShader fragmentShader(fragmentShaderSource);
		std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);

		MeshRenderer meshRenderer(CreateQuad(), shaderProgram);
		window.SetRenderCallback(std::bind_front(&MeshRenderer::Render, &meshRenderer));

		window.Display();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}