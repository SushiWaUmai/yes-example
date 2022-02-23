#include <iostream>
#include "sandbox.h"

void Sandbox::Init()
{
    Application::Init();
    std::cout << "Init()" << std::endl;

    float vertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f, 
         0.0f,  0.5f, 
    };

    unsigned int indices[] = {
        0, 1, 2
    };

    vertexBuffer.Init(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    indexBuffer.Init(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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
