#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"
#include "CameraController.h"
#include "MeshData.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Window.h"

const char* vertexShaderSource = R"s(
#version 460 core
layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inNormal;

layout (std140, binding = 0) uniform Camera
{
    mat4 view;
    mat4 projection;
} camera;

out vec3 Normal;

void main()
{
    gl_Position = camera.projection * camera.view * vec4(inPos, 1.0f);
    Normal = inNormal;
})s";

const char* fragmentShaderSource = R"s(
#version 460 core
out vec4 FragColor;

in vec3 Normal;

void main()
{
    FragColor = vec4(abs(Normal), 1.0f);
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
			glm::perspective(glm::radians(45.0f), 800.0f / 600, 0.1f, 100.0f)
		});

		CameraController cameraController(&camera);

		VertexShader vertexShader(vertexShaderSource);
		FragmentShader fragmentShader(fragmentShaderSource);
		std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);

		MeshRenderer meshRenderer(CreateCube(), shaderProgram);
		window.SetRenderCallback(std::bind_front(&MeshRenderer::Render, &meshRenderer));
		window.SetKeyboardCallback(std::bind_front(&CameraController::HandlePlayerInput, &cameraController));

		window.Display();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}