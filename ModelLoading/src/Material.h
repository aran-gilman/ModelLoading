#pragma once

#include <map>
#include <memory>

#include "ShaderProgram.h"

class Texture;

class Material
{
public:
	using TextureMap = std::map<unsigned int, std::shared_ptr<Texture>>;
	Material(ShaderProgram shader, TextureMap textures);
	Material(ShaderProgram shader);

	void Bind() const;

private:
	ShaderProgram shader;
	TextureMap textures;
};