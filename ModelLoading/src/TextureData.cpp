#include "TextureData.h"

#include <format>
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TextureData ReadImageFile(const std::string& path)
{
	TextureData textureData{};
	int nrChannels;
	stbi_set_flip_vertically_on_load(true);
	textureData.data = stbi_load(path.c_str(), &textureData.width, &textureData.height, &nrChannels, 0);
	if (textureData.data == nullptr)
	{
		throw std::runtime_error(std::format("Failed to load image: {}", path));
	}
	textureData.hasAlpha = nrChannels == 4;
	return textureData;
}
