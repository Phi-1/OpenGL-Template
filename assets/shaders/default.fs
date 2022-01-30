#version 330 core

out vec4 fragColor;

in vec2 texcoords;

uniform sampler2D texdata;

void main() {
    fragColor = texture(texdata, texcoords);
}