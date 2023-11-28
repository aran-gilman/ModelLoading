#pragma once

#include <GL/glew.h>

enum class BufferBindingTarget : GLenum
{
	Array = GL_ARRAY_BUFFER,
	ElementArray = GL_ELEMENT_ARRAY_BUFFER,
	Uniform = GL_UNIFORM_BUFFER
};

enum class BufferUsage : GLenum
{
	StaticDraw = GL_STATIC_DRAW
};

template <BufferBindingTarget TTarget>
class ManagedBuffer
{
public:
	constexpr static BufferBindingTarget Target = TTarget;

	ManagedBuffer()
	{
		glCreateBuffers(1, &name);
	}

	~ManagedBuffer()
	{
		glDeleteBuffers(1, &name);
	}

	unsigned int Name() const { return name; }

	ManagedBuffer(const ManagedBuffer&) = delete;
	ManagedBuffer& operator=(const ManagedBuffer&) = delete;

private:
	unsigned int name;
};

