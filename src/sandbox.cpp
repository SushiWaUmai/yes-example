#include <stdio.h>
#include "sandbox.h"
#include <glm/gtx/transform.hpp>

void Sandbox::Start()
{
    Application::Start();
    printf("Init()\n");

    using namespace yes;
    {
        frameBuffer = FrameBuffer::Create();

        // Create the texture
        renderTexture = Texture::Create(800, 600, 3, NULL);
        renderTexture->Bind();

        frameBuffer->AttachTexture(renderTexture);

        // Create a vertex array
        frameBufferVertexArray = VertexArray::Create();

        // fill the entire screen
        float positionData[] = {
            -1.0f, -1.0f,
             1.0f, -1.0f,
            -1.0f,  1.0f,
             1.0f,  1.0f,
        };

        float uvData[] = {
            0.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
        };

        unsigned int indices[] = {
            0, 1, 2,
            1, 2, 3
        };

        Ref<VertexBuffer> position = VertexBuffer::Create(4, ShaderDataType::V2F, positionData, GL_STATIC_DRAW);
        Ref<VertexBuffer> uv = VertexBuffer::Create(4, ShaderDataType::V2F, uvData, GL_STATIC_DRAW);
        Ref<IndexBuffer> indexBuffer = IndexBuffer::Create(2, ShaderDataType::V3U, indices, GL_STATIC_DRAW);

        // create the vertex array
        frameBufferVertexArray->AddVertexBuffer(0, position);
        frameBufferVertexArray->AddVertexBuffer(1, uv);
        frameBufferVertexArray->SetIndexBuffer(indexBuffer);

        frameBufferShader = Shader::Create();
        frameBufferShader->Load("./assets/pp.vert", "./assets/pp.frag");
    }

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

    Ref<VertexBuffer> positionBuffer = VertexBuffer::Create(4, ShaderDataType::V2F, vertices, GL_STATIC_DRAW);
    Ref<VertexBuffer> colorBuffer = VertexBuffer::Create(4, ShaderDataType::V3F, colors, GL_STATIC_DRAW);
    Ref<VertexBuffer> uvBuffer = VertexBuffer::Create(4, ShaderDataType::V2F, uvs, GL_STATIC_DRAW);

    Ref<IndexBuffer> indexBuffer = IndexBuffer::Create(2, ShaderDataType::V3U, indices, GL_STATIC_DRAW);
    squareVertexArray = VertexArray::Create();

    shader = Shader::Create();
    shader->Load("./assets/sq.vert", "./assets/sq.frag");

    texture = Texture::Create("./assets/noise.png");

    squareVertexArray->AddVertexBuffer(0, positionBuffer);
    squareVertexArray->AddVertexBuffer(1, colorBuffer);
    squareVertexArray->AddVertexBuffer(2, uvBuffer);
    squareVertexArray->SetIndexBuffer(indexBuffer);

    shader->SetUniformM4F("_transformation", transformation);
}

void Sandbox::Update()
{
    {
        frameBuffer->Bind();
        renderer.Clear();

        texture->Bind();
        shader->Use();
        renderer.Submit(squareVertexArray);

        frameBuffer->Unbind();
        texture->Unbind();
        shader->Unuse();
    }

    {
        renderer.Clear();

        frameBufferShader->Use();
        renderTexture->Bind();

        renderer.Submit(frameBufferVertexArray);

        renderTexture->Unbind();
        frameBufferShader->Unuse();
    }

    Application::Update();
}
