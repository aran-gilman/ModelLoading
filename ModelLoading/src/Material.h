#pragma once

#include "ShaderProgram.h"

class Material
{
public:
	Material(ShaderProgram shader);

private:
	ShaderProgram shader;
};