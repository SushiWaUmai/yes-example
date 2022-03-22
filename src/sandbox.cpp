#include <iostream>
#include "sandbox.h"
#include <glm/gtx/transform.hpp>

void Sandbox::Init()
{
    Application::Init();
    std::cout << "Init()" << std::endl;

    using namespace yes;

    float vertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.5f,  0.5f,
        -0.5f,  0.5f,
    };

    float colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f,
    };

    float uvs[] = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    // glm::mat4 transformation = glm::mat4(1.0f) * glm::translate(glm::vec3(0.25f, 0.25f, 0.0f)) * glm::rotate(glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 transformation = glm::mat4(1.0f);

    vertexArray = VertexArray::Create();
    Ref<VertexBuffer> positionBuffer = VertexBuffer::Create(4, ShaderDataType::V2F, vertices, GL_STATIC_DRAW);
    Ref<VertexBuffer> colorBuffer = VertexBuffer::Create(4, ShaderDataType::V3F, colors, GL_STATIC_DRAW);
    Ref<VertexBuffer> uvBuffer = VertexBuffer::Create(4, ShaderDataType::V2F, uvs, GL_STATIC_DRAW);
    
    Ref<IndexBuffer> indexBuffer = IndexBuffer::Create(2, ShaderDataType::V3U, indices, GL_STATIC_DRAW);

    shader = Shader::Create("./assets/vert.glsl", "./assets/frag.glsl");

    texture = Texture::Create("./assets/noise.png");
    texture->Bind();

    vertexArray->AddVertexBuffer(0, positionBuffer);
    vertexArray->AddVertexBuffer(1, colorBuffer);
    vertexArray->AddVertexBuffer(2, uvBuffer);
    vertexArray->SetIndexBuffer(indexBuffer);

    shader->SetUniformM4F("_transformation", transformation);
}

void Sandbox::Update()
{
    renderer.Submit(vertexArray);
    Application::Update();
}

void Sandbox::Terminate()
{
    Application::Terminate();
    std::cout << "Terminate()" << std::endl;
}
