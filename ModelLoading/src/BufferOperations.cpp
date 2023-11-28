#include "BufferOperations.h"

void BindVertexArray(const ManagedVertexArray& buffer)
{
	glBindVertexArray(buffer.Name());
}

void UnbindBuffer(BufferBindingTarget target)
{
	glBindBuffer(static_cast<GLenum>(target), 0);
}

void UnbindVertexArray()
{
	glBindVertexArray(0);
}
