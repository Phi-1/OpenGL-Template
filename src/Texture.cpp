#include <GLAD/glad.h>
#include "Texture.h"

Texture::Texture(unsigned char* imageData, int width, int height, int nrchannels) : _width(width), _height(height), _nrchannels(nrchannels) {
    glGenTextures(1, &_ID);
    glBindTexture(GL_TEXTURE_2D, _ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float borderColor[] = { 255.0f, 0.0f, 191.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
}

unsigned int* Texture::getID() {
    // Returns pointer for GL's deleteTextures function
    return &_ID;
}