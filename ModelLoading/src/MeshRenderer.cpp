#include "MeshRenderer.h"

#include <stdexcept>

#include <GL/glew.h>

#include "BufferOperations.h"
#include "Material.h"

MeshRenderer::MeshRenderer(const MeshData& meshData, std::shared_ptr<Material> material) :
	material(material)
{
	if (material == nullptr)
	{
		throw std::invalid_argument("material must be non-null");
	}

	SetBufferData(vbo, meshData.vertices, BufferUsage::StaticDraw);
	SetBufferData(ebo, meshData.indices, BufferUsage::StaticDraw);
	SetVertexArrayElements(vao, ebo);

	DefineVertexAttribute(
		vao, vbo,
		0, ComponentCount::Three,
		sizeof(Vertex), offsetof(Vertex, position));

	DefineVertexAttribute(
		vao, vbo,
		1, ComponentCount::Three,
		sizeof(Vertex), offsetof(Vertex, normal));

	DefineVertexAttribute(
		vao, vbo,
		2, ComponentCount::Two,
		sizeof(Vertex), offsetof(Vertex, uv));

	drawCount = meshData.indices.size();
}

void MeshRenderer::Render(double elapsedTime) const
{
	material->Bind();
	BindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
}
