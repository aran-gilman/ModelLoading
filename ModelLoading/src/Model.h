#pragma once

#include <string>
#include <vector>

#include "MeshData.h"

struct Model
{
	std::vector<MeshData> meshData;
	std::vector<Model> children;
};

Model LoadModel(const std::string& path);

