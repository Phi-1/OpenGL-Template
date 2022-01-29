#ifndef RESOURCES_H
#define RESOURCES_H

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Shader.h"

namespace resources {
    
    std::map<std::string, Shader*> shaders;

    std::string readFile(std::string filename) {
        std::string content;
        try {
            std::ifstream file(filename);
            std::stringstream contentstream;
            contentstream << file.rdbuf();
            file.close();
            content = contentstream.str();
        } catch (std::exception e) {
            std::cout << "ERROR || Failed to load file '" << filename << "'" << std::endl;
        }
        return content;
    }

    Shader loadShader(std::string vertexFile, std::string fragmentFile, std::string name) {
        std::string vertexSource = readFile(vertexFile);
        std::string fragmentSource = readFile(fragmentFile);
        Shader* shader = new Shader(vertexSource, fragmentSource);
        shaders[name] = shader;
        return *shaders[name];
    }

    Shader getShader(std::string name) {
        return *shaders[name];
    }

    void deleteShader(std::string name) {
        delete shaders[name];
        shaders[name] = nullptr;
    }

}

#endif