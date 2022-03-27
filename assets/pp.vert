#version 330 core

layout (location = 0) in vec3 _pos;
layout (location = 1) in vec2 _uv;

out vec2 _texCoord;

void main() {
    gl_Position = vec4(_pos, 1.0);
    _texCoord = _uv;
}