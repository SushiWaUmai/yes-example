#version 330 core

in vec2 _texCoord;
out vec4 FragColor;

uniform sampler2D _texture;

void main() {
    // Invert the colors
    FragColor = 1.0f - texture(_texture, _texCoord);
}