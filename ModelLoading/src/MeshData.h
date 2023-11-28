#pragma once

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
