#version 330 core

layout(location=0) in vec2 aPos;
layout(location=1) in vec2 aTexcoords;

out vec2 texcoords;

uniform mat4 model;
uniform mat4 projection;

void main() {
    texcoords = aTexcoords;
    gl_Position = projection * model * vec4(aPos, 0.0f, 1.0f);
}