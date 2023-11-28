#include "MeshRenderer.h"

#include "BufferOperations.h"
#include "GLEnums.h"

MeshRenderer::MeshRenderer(const MeshData& meshData)
{
	SetBufferData(vbo, meshData.vertices, BufferUsage::StaticDraw);
	SetBufferData(ebo, meshData.indices, BufferUsage::StaticDraw);
}

void MeshRenderer::Render()
{
}
