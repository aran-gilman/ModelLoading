#include "ManagedBuffer.h"

#include <utility>

#include <GL/glew.h>

ManagedBuffer::ManagedBuffer()
{
	glCreateBuffers(1, &name);
}

ManagedBuffer::~ManagedBuffer()
{
	glDeleteBuffers(1, &name);
}
