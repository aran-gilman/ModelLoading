#pragma once

#include "Shader.h"

class ShaderProgram
{
public:
	ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader);
	~ShaderProgram();

	unsigned int Name() const { return name; }

	ShaderProgram(const ShaderProgram&) = delete;
	ShaderProgram& operator=(const ShaderProgram&) = delete;

private:
	unsigned int name;
};

void BindShaderProgram(const ShaderProgram& shaderProgram);
void UnbindShaderProgram();