#pragma once

#include <memory>

#include "ManagedBuffer.h"
#include "ManagedVertexArray.h"
#include "MeshData.h"

class Material;

class MeshRenderer
{
public:
	MeshRenderer(const MeshData& meshData, std::shared_ptr<Material> material);

	void Render(double elapsedTime) const;

private:
	ArrayBuffer vbo;
	ElementBuffer ebo;
	ManagedVertexArray vao;

	std::shared_ptr<Material> material;

	int drawCount;
};

