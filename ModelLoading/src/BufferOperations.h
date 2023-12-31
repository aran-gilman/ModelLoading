#pragma once

#include <vector>

#include <GL/glew.h>

#include "ManagedBuffer.h"
#include "ManagedVertexArray.h"

template <BufferBindingTarget Target, typename T>
void SetBufferData(const ManagedBuffer<Target>& buffer, const std::vector<T>& data, BufferUsage usage)
{
	glNamedBufferData(buffer.Name(), data.size() * sizeof(T), data.data(), static_cast<GLenum>(usage));
}

template <BufferBindingTarget Target, typename T>
void SetBufferData(const ManagedBuffer<Target>& buffer, const T& data, BufferUsage usage)
{
	glNamedBufferData(buffer.Name(), sizeof(data), &data, static_cast<GLenum>(usage));
}

template <typename T>
void SetBufferData(const UniformBuffer& buffer, const T& data, BufferUsage usage)
{
	static_assert(sizeof(T) % 16 == 0, "Uniform buffer data type size must be a multiple of 16.");
	glNamedBufferData(buffer.Name(), sizeof(data), &data, static_cast<GLenum>(usage));
}

// Unlike SetBuffer(), we do want to support non-16-aligned types for uniform
// buffers when updating the buffer, so no specialization is needed.
template <BufferBindingTarget Target, typename T>
void UpdateBufferData(const ManagedBuffer<Target>& buffer, const T& data, ptrdiff_t offset = 0)
{
	glNamedBufferSubData(buffer.Name(), offset, sizeof(T), &data);
}

template <BufferBindingTarget Target>
void BindBuffer(const ManagedBuffer<Target>& buffer)
{
	glBindBuffer(static_cast<GLenum>(Target), buffer.Name());
}

void BindVertexArray(const ManagedVertexArray& vao);
void UnbindBuffer(BufferBindingTarget target);
void UnbindVertexArray();

void BindUniformBlock(const UniformBuffer& buffer, int bindingPoint);

void SetVertexArrayElements(const ManagedVertexArray& vao, const ManagedBuffer<BufferBindingTarget::ElementArray>& ebo);

enum class ComponentCount : int
{
	One = 1,
	Two = 2,
	Three = 3,
	Four = 4
};
void DefineVertexAttribute(
	const ManagedVertexArray& vao,
	const ManagedBuffer<BufferBindingTarget::Array>& vbo,
	int bindingPoint,
	ComponentCount size,
	int stride,
	ptrdiff_t offset);