#include "GLEnums.h"

std::string ToString(ShaderType shaderType)
{
	switch (shaderType)
	{
	case ShaderType::Vertex:
		return "Vertex";
	case ShaderType::Fragment:
		return "Fragment";
	}
	return "";
}
