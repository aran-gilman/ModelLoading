#include "Material.h"

Material::Material(ShaderProgram shader) :
	shader(std::move(shader))
{
}

void Material::Bind() const
{
	BindShaderProgram(shader);
}
