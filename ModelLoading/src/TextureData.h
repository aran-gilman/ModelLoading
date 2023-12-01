#pragma once

#include <string>

struct TextureData
{
	unsigned char* data;
	int width;
	int height;
	bool hasAlpha;
};

TextureData ReadImageFile(const std::string& path);