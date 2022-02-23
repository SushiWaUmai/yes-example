#include <iostream>
#include "sandbox.h"

void Sandbox::Init()
{
    Application::Init();
    std::cout << "Init()" << std::endl;

    float vertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.5f,  0.5f,
        -0.5f,  0.5f,
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0 
    };

    vertexBuffer = yes::VertexBuffer();
    indexBuffer = yes::IndexBuffer();
    shader = yes::Shader();

    vertexBuffer.Init(sizeof(vertices), vertices, GL_STATIC_DRAW);
    indexBuffer.Init(sizeof(indices), indices, GL_STATIC_DRAW);

    shader.Init("./assets/vert.glsl", "./assets/frag.glsl");
    shader.Use();

    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    vertexBuffer.Bind();
    indexBuffer.Bind();

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void *)0);
}

void Sandbox::Update()
{
    Application::Update();
    std::cout << "Update()" << std::endl;
}

void Sandbox::Terminate()
{
    Application::Terminate();
    std::cout << "Terminate()" << std::endl;
}
