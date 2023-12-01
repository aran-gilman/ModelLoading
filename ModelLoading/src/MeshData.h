#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 uv;
};

struct MeshData
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
};

MeshData CreateQuad();
MeshData CreateCube();

struct Model
{
	std::vector<MeshData> meshData;
	std::vector<Model> children;
};

Model LoadModel(const std::string& path);
