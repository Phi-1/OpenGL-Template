#include <GLAD/glad.h>
#include "Renderer.h"

Renderer::Renderer() {
    _createQuadVAO();
}

void Renderer::drawQuad() {
    glBindVertexArray(_quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void Renderer::_createQuadVAO() {
    float vertices[] = {
        -0.5f, -0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &_quadVAO);
    glBindVertexArray(_quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}