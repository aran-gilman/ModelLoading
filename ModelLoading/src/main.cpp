#include <filesystem>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

#include <glm/glm.hpp>

#include "Camera.h"
#include "CameraController.h"
#include "FileUtil.h"
#include "Material.h"
#include "MeshData.h"
#include "MeshRenderer.h"
#include "Model.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "TextureData.h"
#include "Texture.h"
#include "Window.h"

class MaterialManager
{
public:
	MaterialManager(
		std::string textureDirectory,
		VertexShader vertexShader,
		FragmentShader fragmentShader) :
		textureDirectory(textureDirectory),
		vertexShader(std::move(vertexShader)),
		fragmentShader(std::move(fragmentShader))
	{
	}

	std::shared_ptr<Material> GetOrLoad(const std::string& path)
	{
		if (auto existing = loadedMaterials.find(path);
			existing != loadedMaterials.end())
		{
			return existing->second;
		}
		 
		std::shared_ptr<Texture> texture = std::make_shared<Texture>(
			ReadImageFile((textureDirectory / path).string()));
		std::shared_ptr<Material> material = std::make_shared<Material>(ShaderProgram(vertexShader, fragmentShader), Material::TextureMap{ { 0, texture } });
		loadedMaterials.emplace(path, material);
		return material;
	}

private:
	std::filesystem::path textureDirectory;
	VertexShader vertexShader;
	FragmentShader fragmentShader;

	std::map<std::string, std::shared_ptr<Material>> loadedMaterials;
};

class Scene
{
public:
	Scene(Window* window) :
		camera(glm::vec3(0.0f, 0.0f, 3.0f), 800.0f / 600.0f, 45.0f),
		cameraController(&camera)
	{
		VertexShader vertexShader(ReadTextFile("resources/shaders/standard.vert"));
		FragmentShader fragmentShader(ReadTextFile("resources/shaders/unlit.frag"));
		MaterialManager materialManaged(
			"resources/models/", std::move(vertexShader), std::move(fragmentShader));

		AddModel(LoadModel("resources/models/backpack.obj"), &materialManaged);

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

	void AddModel(const Model& model, MaterialManager* materialManager)
	{
		for (const Mesh& mesh : model.meshes)
		{
			renderers.push_back(
				MeshRenderer(mesh.meshData, materialManager->GetOrLoad(mesh.texturePath)));
		}
		for (const Model& child : model.children)
		{
			AddModel(child, materialManager);
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