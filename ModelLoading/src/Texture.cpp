#include "Texture.h"

#include <utility>

#include <GL/glew.h>

Texture::Texture(const TextureData& textureData)
{
	glCreateTextures(GL_TEXTURE_2D, 1, &name);
	glTextureParameteri(name, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTextureParameteri(name, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTextureParameteri(name, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTextureParameteri(name, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned int format = textureData.hasAlpha ? (unsigned int)GL_RGBA : (unsigned int)GL_RGB;
	unsigned int internalFormat = textureData.hasAlpha ? (unsigned int)GL_RGBA8 : (unsigned int)GL_RGB8;
	glTextureStorage2D(
		name, 1, internalFormat,
		textureData.width, textureData.height);
	glTextureSubImage2D(
		name, 0,
		0, 0,
		textureData.width, textureData.height,
		format, GL_UNSIGNED_BYTE,
		textureData.data);
	glGenerateTextureMipmap(name);
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
