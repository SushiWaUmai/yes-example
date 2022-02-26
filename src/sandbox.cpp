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

    Ref<VertexBuffer> vertexBuffer = VertexBuffer::Create(sizeof(vertices), vertices, GL_STATIC_DRAW);
    Ref<IndexBuffer> indexBuffer = IndexBuffer::Create(sizeof(indices), indices, GL_STATIC_DRAW);
    Ref<VertexArray> vertexArray = VertexArray::Create();

    Ref<Shader> shader = Shader::Create("./assets/vert.glsl", "./assets/frag.glsl");
    shader->Use();

    vertexArray->Bind();
    vertexBuffer->Bind();
    indexBuffer->Bind();

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    std::cout << ShaderDataTypeUtils::ShaderDataTypeToSize(ShaderDataType::Float) << std::endl;
    vertexBuffer->Unbind();

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
