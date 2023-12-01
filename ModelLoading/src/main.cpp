#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <glm/glm.hpp>

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

class Scene
{
public:
	Scene(Window* window) :
		camera(glm::vec3(0.0f, 0.0f, 3.0f), 800.0f / 600.0f, 45.0f),
		cameraController(&camera)
	{
		VertexShader vertexShader(vertexShaderSource);
		FragmentShader fragmentShader(fragmentShaderSource);
		std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);

		AddModel(LoadModel("resources/models/bookA.fbx"), shaderProgram);

		window->SetRenderCallback(std::bind_front(&Scene::Render, this));
		window->SetUpdateCallback(std::bind_front(&CameraController::Update, &cameraController));
		window->SetKeyboardCallback(std::bind_front(&CameraController::HandleKeyboardInput, &cameraController));
		window->SetScrollCallback(std::bind_front(&CameraController::HandleScrollInput, &cameraController));
	}

	void Render(double elapsedTime)
	{
		for (const MeshRenderer& renderer : renderers)
		{
			renderer.Render(elapsedTime);
		}
	}

private:
	std::vector<MeshRenderer> renderers;

	Camera camera;
	CameraController cameraController;

	void AddModel(const Model& model, std::shared_ptr<ShaderProgram> shaderProgram)
	{
		for (const MeshData& mesh : model.meshData)
		{
			renderers.push_back(MeshRenderer(mesh, shaderProgram));
		}
		for (const Model& child : model.children)
		{
			AddModel(child, shaderProgram);
		}
	}
};

int main(int argc, char* argv[])
{
	try
	{
		Window window(800, 600, "Model Loading Test");
		Scene scene(&window);
		window.Display();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}