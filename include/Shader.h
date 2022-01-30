#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <string>

class Shader {
public:
    Shader(std::string vertexSource, std::string fragmentSource);
    void bind();
    void unbind();
    void setUniformMat4f(std::string name, glm::mat4 matrix);
    unsigned int getID();
private:
    unsigned int _ID;
};

#endif