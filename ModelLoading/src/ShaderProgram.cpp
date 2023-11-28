#include "ShaderProgram.h"

#include <format>
#include <stdexcept>

#include <GL/glew.h>

ShaderProgram::ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader) :
	name(glCreateProgram())
{
	glAttachShader(name, vertexShader.Name());
	glAttachShader(name, fragmentShader.Name());
	glLinkProgram(name);

	int success;
	char infoLog[512];
	glGetProgramiv(name, GL_LINK_STATUS, &success);
	if (!success)
	{
		glDeleteProgram(name);
		throw std::runtime_error(std::format("Failed to link shader program: {}", infoLog));
	}
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(name);
}

void BindShaderProgram(const ShaderProgram& shaderProgram)
{
	glUseProgram(shaderProgram.Name());
}

void UnbindShaderProgram()
{
	glUseProgram(0);
}
