#pragma once

#include "TextureData.h"

class Texture
{
public:
	Texture(const TextureData& textureData);
	~Texture();

	unsigned int Name() const { return name; }

	Texture(const Texture&) = delete;
	Texture& operator=(const Texture&) = delete;

	Texture(Texture&& other) noexcept;
	Texture& operator=(Texture&& other) noexcept;

private:
	unsigned int name;
};

