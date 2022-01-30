#include <GLAD/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"


Renderer::Renderer(Shader shader) : _shader(shader) {
    _createQuadVAO();
}

void Renderer::drawQuad(glm::vec2 position, glm::vec2 size, Texture texture) {
    glBindVertexArray(_quadVAO);
    _shader.bind();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));

    glm::mat4 projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, 0.0f, 1.0f);
    _shader.setUniformMat4f("model", model);
    _shader.setUniformMat4f("projection", projection);

    glBindTexture(GL_TEXTURE_2D, *texture.getID());

    glDrawArrays(GL_TRIANGLES, 0, 6);

    _shader.unbind();
    glBindVertexArray(0);
}

void Renderer::setShader(Shader shader) {
    _shader = shader;
}

void Renderer::_createQuadVAO() {
    float vertices[] = {
        // Position   // Texture
        -1.0f, -1.0f, 0.0f, 0.0f,
         1.0f,  1.0f, 1.0f, 1.0f,
        -1.0f,  1.0f, 0.0f, 1.0f,
        -1.0f, -1.0f, 0.0f, 0.0f,
         1.0f, -1.0f, 1.0f, 0.0f,
         1.0f,  1.0f, 1.0f, 1.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &_quadVAO);
    glBindVertexArray(_quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}