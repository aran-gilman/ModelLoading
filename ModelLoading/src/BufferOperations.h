#pragma once

#include <vector>

#include <GL/glew.h>

#include "GLEnums.h"
#include "ManagedBuffer.h"

template <BufferBindingTarget Target, typename T>
void SetBufferData(const ManagedBuffer<Target>& buffer, const std::vector<T>& data, BufferUsage usage)
{
	glNamedBufferData(buffer.Name(), data.size() * sizeof(T), data.data(), static_cast<GLenum>(usage));
}