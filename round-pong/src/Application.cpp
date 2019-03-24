#include "pch.h"
#include "Application.h"


// Declaration of static variable
Application* Application::m_instance;

Application * Application::create()
{
    if (!m_instance)
    {
        m_instance = new Application();
    }

    return m_instance;
}

Application::Application()
{
    RP_LOG("Application constructed.");
    m_window = std::unique_ptr<Window>(Window::create());
}

Application::~Application()
{
    RP_LOG("Application destroyed.");
}

void Application::run()
{
    RP_LOG("App is running.");

    while (!glfwWindowShouldClose(m_window->getWindow()))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        m_window->onUpdate();
    }
}