#include <yes/yes.h>

class Sandbox : public yes::Application
{
public:
    void Init() override;
    void Update() override;
    void Terminate() override;

private:
    GLuint vao;
    yes::VertexBuffer vertexBuffer;
    yes::IndexBuffer indexBuffer;
    yes::Shader shader;
};
