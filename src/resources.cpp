#include "resources.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <GLAD/glad.h>
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Shader.h"
#include "Texture.h"

namespace resources {

    std::map<std::string, Shader*> shaders;
    std::map<std::string, Texture*> textures;

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

    Texture loadTexture(std::string filepath, std::string name) {
        int width, height, nrchannels;
        unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &nrchannels, 0);
        if (!data) {
            std::cout << "ERROR || Failed to load image: '" << filepath << "'" << std::endl;
        }
        Texture* texture = new Texture(data, width, height, nrchannels);
        textures[name] = texture;
        stbi_image_free(data);
        return *textures[name];
    }

    Texture getTexture(std::string name) {
        return *textures[name];
    }

    void deleteShader(std::string name) {
        delete shaders[name];
        shaders[name] = nullptr;
    }

    void deleteTexture(std::string name) {
        delete textures[name];
        textures[name] = nullptr;
    }

    void clear() {
        for (auto shader : shaders) {
            deleteShader(shader.first);
            glDeleteProgram(shader.second->getID());
        }
        for (auto texture : textures) {
            deleteTexture(texture.first);
            glDeleteTextures(1, texture.second->getID());
        }
    }

}