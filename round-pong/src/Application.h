#pragma once
#include "Window.h"

class Application
{
public:
    ~Application();
    static Application* create();
    void run();

private:
    Application();
    static Application* m_instance;
    std::unique_ptr<Window> m_window;
};

