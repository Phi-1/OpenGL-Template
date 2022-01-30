#ifndef RENDERER_H
#define RENDERER_H

#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"

class Renderer {
public:
    Renderer(Shader shader);
    void drawQuad(glm::vec2 position, glm::vec2 size, Texture texture);
    void setShader(Shader shader);
private:
    unsigned int _quadVAO;
    Shader _shader;
    void _createQuadVAO();
};

#endif