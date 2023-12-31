#include "ManagedVertexArray.h"

#include <utility>

#include "GL/glew.h"

ManagedVertexArray::ManagedVertexArray()
{
	glCreateVertexArrays(1, &name);
}

ManagedVertexArray::~ManagedVertexArray()
{
	glDeleteVertexArrays(1, &name);
}

ManagedVertexArray::ManagedVertexArray(ManagedVertexArray&& other) noexcept :
	name(std::exchange(other.name, 0))
{
}

ManagedVertexArray& ManagedVertexArray::operator=(ManagedVertexArray&& other) noexcept
{
	if (this != &other)
	{
		glDeleteVertexArrays(1, &name);
		name = std::exchange(other.name, 0);
	}
	return *this;
}
