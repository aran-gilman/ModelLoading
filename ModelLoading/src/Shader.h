#pragma once

#include <format>
#include <stdexcept>
#include <string>

#include <GL/glew.h>

enum class ShaderType : GLenum
{
	Vertex = GL_VERTEX_SHADER,
	Fragment = GL_FRAGMENT_SHADER,
};
std::string ToString(ShaderType shaderType);

template <ShaderType Type>
class Shader
{
public:
	Shader(const std::string& source) : name(glCreateShader(static_cast<GLenum>(Type)))
	{
		const char* data = source.c_str();
		glShaderSource(name, 1, &data, nullptr);
		glCompileShader(name);

		int success;
		char infoLog[512];
		glGetShaderiv(name, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(name, 512, nullptr, infoLog);
			glDeleteShader(name);
			throw std::runtime_error(std::format("Failed to compile shader of type {0}: {1}", ToString(Type), infoLog));
		}
	}

	~Shader()
	{
		glDeleteShader(name);
	}

	unsigned int Name() const { return name; }

	Shader(const Shader&) = delete;
	Shader& operator=(const Shader&) = delete;

private:
	unsigned int name;
};

using VertexShader = Shader<ShaderType::Vertex>;
using FragmentShader = Shader<ShaderType::Fragment>;
