#include "Material.h"

#include <format>
#include <stdexcept>

#include "Texture.h"

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
	for (const auto& [unit, texture] : textures)
	{
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, texture->Name());
	}
}
