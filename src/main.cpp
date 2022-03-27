#include "sandbox.h"

int main(void)
{
    Sandbox app;
    app.Init("Example Window", 800, 600);
    app.Run();

    return 0;
}
