#include "ManagedVertexArray.h"

#include "GL/glew.h"

ManagedVertexArray::ManagedVertexArray()
{
	glCreateBuffers(1, &name);
}

ManagedVertexArray::~ManagedVertexArray()
{
	glDeleteBuffers(1, &name);
}
