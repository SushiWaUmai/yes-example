#include <iostream>
#include "sandbox.h"

void Sandbox::Init()
{
    using namespace yes;

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

    Ref<VertexArray> vertexArray = VertexArray::Create();
    Ref<VertexBuffer> vertexBuffer = VertexBuffer::Create(4, ShaderDataType::Vec2, vertices, GL_STATIC_DRAW);
    Ref<IndexBuffer> indexBuffer = IndexBuffer::Create(2, ShaderDataType::Int3, indices, GL_STATIC_DRAW);

    Ref<Shader> shader = Shader::Create("./assets/vert.glsl", "./assets/frag.glsl");

    vertexArray->AddVertexBuffer(0, vertexBuffer);
    vertexArray->EnableAllVertexAttributes();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void *)0);
}

void Sandbox::Update()
{
    Application::Update();
}

void Sandbox::Terminate()
{
    Application::Terminate();
    std::cout << "Terminate()" << std::endl;
}
