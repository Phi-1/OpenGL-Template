#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
    Shader(std::string vertexSource, std::string fragmentSource);
    void bind();
    void unbind();
private:
    unsigned int _ID;
};

#endif