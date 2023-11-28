#pragma once

#include <vector>

#include <GL/glew.h>

#include "GLEnums.h"
#include "ManagedBuffer.h"
#include "ManagedVertexArray.h"

template <BufferBindingTarget Target, typename T>
void SetBufferData(const ManagedBuffer<Target>& buffer, const std::vector<T>& data, BufferUsage usage)
{
	glNamedBufferData(buffer.Name(), data.size() * sizeof(T), data.data(), static_cast<GLenum>(usage));
}

template <BufferBindingTarget Target>
void BindBuffer(const ManagedBuffer<Target>& buffer)
{
	glBindBuffer(static_cast<GLenum>(Target), buffer.Name());
}

void BindVertexArray(const ManagedVertexArray& vao);
void UnbindBuffer(BufferBindingTarget target);
void UnbindVertexArray();

void SetVertexArrayElements(const ManagedVertexArray& vao, const ManagedBuffer<BufferBindingTarget::ElementArray>& ebo);