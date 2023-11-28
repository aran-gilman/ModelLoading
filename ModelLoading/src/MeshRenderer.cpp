#include "MeshRenderer.h"

#include "BufferOperations.h"

MeshRenderer::MeshRenderer(const MeshData& meshData)
{
	SetBufferData(vbo, meshData.vertices, BufferUsage::StaticDraw);
	SetBufferData(ebo, meshData.indices, BufferUsage::StaticDraw);
	SetVertexArrayElements(vao, ebo);

	DefineVertexAttribute(
		vao, vbo,
		0, ComponentCount::Three,
		sizeof(Vertex), offsetof(Vertex, position));
}

void MeshRenderer::Render()
{
}
