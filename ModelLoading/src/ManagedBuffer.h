#pragma once

#include <GL/glew.h>

#include "GLEnums.h"

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

