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

	void Render() const;

	MeshRenderer(const MeshRenderer&) = delete;
	MeshRenderer& operator=(const MeshRenderer&) = delete;

private:
	ManagedBuffer<BufferBindingTarget::Array> vbo;
	ManagedBuffer<BufferBindingTarget::ElementArray> ebo;
	ManagedVertexArray vao;

	std::shared_ptr<ShaderProgram> shaderProgram;

	int drawCount;
};

