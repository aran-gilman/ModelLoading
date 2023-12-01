#include "Material.h"

#include <format>
#include <stdexcept>

Material::Material(ShaderProgram shader, TextureMap textures) :
	shader(std::move(shader)),
	textures(std::move(textures))
{
	for (const auto& [unit, texture] : this->textures)
	{
		if (texture == nullptr)
		{
			throw std::runtime_error(std::format("Invalid texture for texture unit {}: must be non-null", unit));
		}
	}
}

Material::Material(ShaderProgram shader) :
	Material(std::move(shader), TextureMap())
{
}

void Material::Bind() const
{
	BindShaderProgram(shader);
}
