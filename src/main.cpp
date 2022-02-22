#include <yes/yes.h>

int main(void)
{
    using namespace yes;

    Application app;
    app.Init();
    app.Run();
    app.Terminate();

    return 0;
}