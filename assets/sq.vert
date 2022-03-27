#version 330 core

layout (location = 0) in vec3 _pos;
layout (location = 1) in vec3 _col;
layout (location = 2) in vec2 _uv;

uniform mat4 _transformation;

out vec3 _fragCol;
out vec2 _texCoord;

void main() {
    gl_Position = _transformation * vec4(_pos, 1.0);
    _fragCol = _col;
    _texCoord = _uv;
}