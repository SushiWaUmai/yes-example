#include "sandbox.h"

int main(void)
{
    Sandbox app;
    app.Init();
    app.Run();
    app.Terminate();

    return 0;
}
