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

void SetVertexArrayElements(const ManagedVertexArray& vao, const ManagedBuffer<BufferBindingTarget::ElementArray>& ebo)
{
	glVertexArrayElementBuffer(vao.Name(), ebo.Name());
}
