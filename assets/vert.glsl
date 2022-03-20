#version 330 core
layout (location = 0) in vec3 _pos;
layout (location = 1) in vec3 _col;

out vec3 _fragCol;

void main() {
    gl_Position = vec4(_pos, 1.0);
    _fragCol = _col;
}