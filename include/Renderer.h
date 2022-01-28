#ifndef RENDERER_H
#define RENDERER_H


class Renderer {
public:
    Renderer();
    void drawQuad();
private:
    unsigned int _quadVAO;
    void _createQuadVAO();
};

#endif