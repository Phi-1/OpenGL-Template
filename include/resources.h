#ifndef RESOURCES_H
#define RESOURCES_H

#include <map>
#include <string>
#include "Shader.h"
#include "Texture.h"

namespace resources {

    std::string readFile(std::string filename);

    Shader loadShader(std::string vertexFile, std::string fragmentFile, std::string name);

    Shader getShader(std::string name);

    Texture loadTexture(std::string filepath, std::string name);

    Texture getTexture(std::string name);

    void deleteShader(std::string name);

    void deleteTexture(std::string name);

    void clear();

}

#endif