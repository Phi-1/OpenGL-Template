#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
public:
    Texture(unsigned char* imageData, int width, int height, int nrchannels);
    void bind();
    void unbind();
    unsigned int* getID(); // Returns pointer for GL's deleteTextures function
private:
    unsigned int _ID;
    int _width, _height;
    int _nrchannels;
};

#endif