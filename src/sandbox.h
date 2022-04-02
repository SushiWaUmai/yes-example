#include <yes/yes.h>

class Sandbox : public yes::Application
{
public:
    void Start(const char *title, int width, int height) override;
    void Update() override;

private:
    yes::Ref<yes::VertexArray> squareVertexArray;
    yes::Ref<yes::Shader> shader;
    yes::Ref<yes::Texture> texture;

    yes::Ref<yes::FrameBuffer> frameBuffer;
    yes::Ref<yes::VertexArray> frameBufferVertexArray;
    yes::Ref<yes::Texture> renderTexture;
    yes::Ref<yes::Shader> frameBufferShader;
};
