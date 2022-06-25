#include "sandbox.h"

int main(void) {
  Sandbox app;
  app.Init("Loading...", 800, 600);
  app.Run();

  return 0;
}
