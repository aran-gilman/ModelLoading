#include "Texture.h"

#include <utility>

#include <GL/glew.h>

Texture::Texture(const TextureData& textureData)
{
	glCreateTextures(GL_TEXTURE_2D, 1, &name);
}

Texture::~Texture()
{
	glDeleteTextures(1, &name);
}

Texture::Texture(Texture&& other) noexcept :
	name(std::exchange(other.name, 0))
{
}

Texture& Texture::operator=(Texture&& other) noexcept
{
	if (this != &other)
	{
		glDeleteTextures(1, &name);
		name = std::exchange(other.name, 0);
	}
	return *this;
}
