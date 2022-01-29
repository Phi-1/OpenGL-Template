#ifndef RENDERER_H
#define RENDERER_H

#include <glm/glm.hpp>
#include "Shader.h"

class Renderer {
public:
    Renderer(Shader shader);
    void drawQuad(glm::vec2 position, glm::vec2 size);
    void setShader(Shader shader);
private:
    unsigned int _quadVAO;
    Shader _shader;
    void _createQuadVAO();
};

#endif