#pragma once

#include <memory>

#include "ManagedBuffer.h"
#include "ManagedVertexArray.h"
#include "MeshData.h"

// [TODO] Replace with Material class
class ShaderProgram;

class MeshRenderer
{
public:
	MeshRenderer(const MeshData& meshData, std::shared_ptr<ShaderProgram> shaderProgram);

	void Render(double elapsedTime) const;

private:
	ArrayBuffer vbo;
	ElementBuffer ebo;
	ManagedVertexArray vao;

	std::shared_ptr<ShaderProgram> shaderProgram;

	int drawCount;
};

