#include <yes/yes.h>

class Sandbox : public yes::Application
{
public:
    void Init() override;
    void Update() override;
    void Terminate() override;
private:
    yes::Ref<yes::VertexArray> vertexArray;
    yes::Ref<yes::Shader> shader;
    yes::Ref<yes::Texture> texture;
};
