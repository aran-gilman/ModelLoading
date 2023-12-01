#include "FileUtil.h"

#include <fstream>
#include <sstream>

std::string ReadTextFile(const std::string& path)
{
    std::ifstream fileStream;
    fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fileStream.open(path);
    std::stringstream stringStream;
    stringStream << fileStream.rdbuf();
    return stringStream.str();
}
