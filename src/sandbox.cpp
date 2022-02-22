#include <iostream>
#include "sandbox.h"

void Sandbox::Init()
{
    Application::Init();
    std::cout << "Init()" << std::endl;
}

void Sandbox::Update()
{
    Application::Update();
    std::cout << "Update()" << std::endl;
}

void Sandbox::Terminate()
{
    Application::Terminate();
    std::cout << "Terminate()" << std::endl;
}