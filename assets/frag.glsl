#version 330 core
in vec3 _fragCol;
out vec4 FragColor;

void main() {
    FragColor = vec4(_fragCol, 1.0);
}