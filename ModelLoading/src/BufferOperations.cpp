#include "BufferOperations.h"

void BindVertexArray(const ManagedVertexArray& vao)
{
	glBindVertexArray(vao.Name());
}

void UnbindBuffer(BufferBindingTarget target)
{
	glBindBuffer(static_cast<GLenum>(target), 0);
}

void UnbindVertexArray()
{
	glBindVertexArray(0);
}

void BindUniformBlock(const UniformBuffer& buffer, int bindingPoint)
{
	glBindBufferBase(static_cast<GLenum>(buffer.Target), bindingPoint, buffer.Name());
}

void SetVertexArrayElements(const ManagedVertexArray& vao, const ManagedBuffer<BufferBindingTarget::ElementArray>& ebo)
{
	glVertexArrayElementBuffer(vao.Name(), ebo.Name());
}

void DefineVertexAttribute(
	const ManagedVertexArray& vao,
	const ManagedBuffer<BufferBindingTarget::Array>& vbo,
	int bindingPoint,
	ComponentCount size,
	int stride,
	ptrdiff_t offset)
{
	glEnableVertexArrayAttrib(vao.Name(), bindingPoint);
	glVertexArrayVertexBuffer(vao.Name(), bindingPoint, vbo.Name(), offset, stride);
	glVertexArrayAttribFormat(
		vao.Name(), bindingPoint,
		static_cast<int>(size), GL_FLOAT, GL_FALSE, offset);
}
