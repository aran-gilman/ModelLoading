#include "FileUtil.h"

#include <format>
#include <fstream>
#include <sstream>

std::string ReadTextFile(const std::string& path)
{
    std::ifstream fileStream(path);
    if (!fileStream.is_open())
    {
        throw std::runtime_error(std::format("Failed to open file: {}", path));
    }
    std::stringstream stringStream;
    stringStream << fileStream.rdbuf();
    return stringStream.str();
}
