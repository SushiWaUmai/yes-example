#version 330 core

in vec3 _fragCol;
in vec2 _texCoord;
out vec4 FragColor;

uniform sampler2D _texture;

void main() {
    FragColor = texture(_texture, _texCoord) * vec4(_fragCol, 1.0);
}