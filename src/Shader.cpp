#include <GLAD/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <string>
#include <iostream>

Shader::Shader(std::string vertexSource, std::string fragmentSource) {
    // Compile vertex and fragment shaders
    const char* vSourceP = vertexSource.c_str();
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vSourceP, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR || Vertex shader compilation failed: \n" << infoLog << std::endl;
    }

    const char* fSourceP = fragmentSource.c_str();
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fSourceP, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR || Fragment shader compilation failed: \n" << infoLog << std::endl;
    }

    // Link program
    _ID = glCreateProgram();
    glAttachShader(_ID, vertexShader);
    glAttachShader(_ID, fragmentShader);
    glLinkProgram(_ID);
    glGetProgramiv(_ID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(_ID, 512, NULL, infoLog);
        std::cout << "ERROR || Shader linking failed: \n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::bind() {
    glUseProgram(_ID);
}

void Shader::unbind() {
    glUseProgram(0);
}

void Shader::setUniformMat4f(std::string name, glm::mat4 matrix) {
    int uid = glGetUniformLocation(_ID, name.c_str());
    glUniformMatrix4fv(uid, 1, GL_FALSE, glm::value_ptr(matrix));
}