#version 330 core
layout (location = 0) in vec3 _pos;
layout (location = 1) in vec3 _col;

uniform mat4 _transformation;

out vec3 _fragCol;

void main() {
    gl_Position = _transformation * vec4(_pos, 1.0);
    // gl_Position = vec4(_pos, 1.0);
    _fragCol = _col;
}