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
