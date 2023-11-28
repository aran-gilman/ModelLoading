#include "MeshRenderer.h"

#include <stdexcept>

#include <GL/glew.h>

#include "BufferOperations.h"
#include "ShaderProgram.h"

MeshRenderer::MeshRenderer(const MeshData& meshData, std::shared_ptr<ShaderProgram> shaderProgram) :
	shaderProgram(shaderProgram)
{
	if (shaderProgram == nullptr)
	{
		throw std::invalid_argument("shaderProgram must be non-null");
	}

	SetBufferData(vbo, meshData.vertices, BufferUsage::StaticDraw);
	SetBufferData(ebo, meshData.indices, BufferUsage::StaticDraw);
	SetVertexArrayElements(vao, ebo);

	DefineVertexAttribute(
		vao, vbo,
		0, ComponentCount::Three,
		sizeof(Vertex), offsetof(Vertex, position));

	drawCount = meshData.indices.size();
}

void MeshRenderer::Render()
{
	BindShaderProgram(*shaderProgram);
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
}
