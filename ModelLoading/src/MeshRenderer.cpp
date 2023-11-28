#include "MeshRenderer.h"

#include "BufferOperations.h"
#include "GLEnums.h"

MeshRenderer::MeshRenderer(const MeshData& meshData)
{
	SetBufferData(vbo, meshData.vertices, BufferUsage::StaticDraw);
	SetBufferData(ebo, meshData.indices, BufferUsage::StaticDraw);

	BindVertexArray(vao);
	BindBuffer(ebo);
	UnbindVertexArray();
}

void MeshRenderer::Render()
{
}
