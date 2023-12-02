#pragma once

#include <string>
#include <vector>

#include "MeshData.h"

struct Mesh
{
	MeshData meshData;
	std::string texturePath;
};

struct Model
{
	std::vector<Mesh> meshes;
	std::vector<Model> children;
};

Model LoadModel(const std::string& path);

