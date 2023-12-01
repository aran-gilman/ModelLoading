#include "Material.h"

Material::Material(ShaderProgram shader) :
	shader(std::move(shader))
{
}
