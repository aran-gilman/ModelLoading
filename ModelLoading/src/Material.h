#pragma once

#include "ShaderProgram.h"

class Material
{
public:
	Material(ShaderProgram shader);

	void Bind() const;

private:
	ShaderProgram shader;
};