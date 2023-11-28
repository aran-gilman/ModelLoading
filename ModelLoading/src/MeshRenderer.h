#pragma once

#include "ManagedBuffer.h"
#include "ManagedVertexArray.h"
#include "MeshData.h"

class MeshRenderer
{
public:
	MeshRenderer(const MeshData& meshData);

	void Render();

	MeshRenderer(const MeshRenderer&) = delete;
	MeshRenderer& operator=(const MeshRenderer&) = delete;

private:
	ManagedBuffer<BufferBindingTarget::Array> vbo;
	ManagedBuffer<BufferBindingTarget::ElementArray> ebo;
	ManagedVertexArray vao;
};

