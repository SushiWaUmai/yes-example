#include <yes/yes.h>

class Sandbox : public yes::Application
{
public:
    void Init() override;
    void Update() override;
    void Terminate() override;
};