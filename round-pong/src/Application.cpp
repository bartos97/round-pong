#include "pch.h"
#include "Application.h"
#include "Renderer.h"
#include <math.h>


// Declaration of static variable
Application* Application::m_instance;


Application::Application()
{
    RP_LOG("Application constructed.");
    m_window = std::unique_ptr<Window>(Window::create());

    APP_BIND_EVENT(WindowClose);
    APP_BIND_EVENT(WindowResize);
    APP_BIND_EVENT(KeyPress);
    APP_BIND_EVENT(KeyRelease);
    APP_BIND_EVENT(MouseMove);
    APP_BIND_EVENT(MouseButtonPress);
    APP_BIND_EVENT(MouseButtonRelease);

    m_isRunning = true;
}


Application::~Application()
{
    RP_LOG("Application destroyed.");
}


Application * Application::create()
{
    if (!m_instance) m_instance = new Application();
    return m_instance;
}


void Application::run()
{
    RP_LOG("App starts running.");    

    float vertices1[] = {
        //position   
        -1.0f, -1.0f,
         0.0f, -1.0f,
         0.0f, 0.0f, 
        -1.0f, 0.0f, 
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    Shader shader("src/Shaders/test.vert", "src/Shaders/test.frag");

    VertexBuffer vb(sizeof(vertices1), vertices1);
    ElementBuffer eb(6, indices);

    BufferLayout layout;
    layout.add<float>(2); //position

    VertexArray va(vb, eb, layout);
    Renderer renderer;

    va.unbind();
    vb.unbindAll();
    eb.unbindAll();

    float i, arg;
    i = arg = 0.0f;

    while (m_isRunning)
    {
        renderer.clearScreen();

        arg += 0.01f;
        i = sin(arg) / 2.0f + 0.5f;

        shader.setUniform("uniformColor", i, 0.5f, 0.5f);
        shader.setUniform("uniformPos", i);

        renderer.draw(va, shader);

        m_window->onUpdate();
    }
}


void Application::onWindowClose(WindowCloseEvent & e)
{
    RP_EVENT_LOG(e, "Window closed.");
    m_isRunning = false;
    e.m_isHandled = true;
}


void Application::onWindowResize(WindowResizeEvent & e)
{
    RP_EVENT_LOG(e, "Window resized to %d x %d", e.getWidth(), e.getHeight());
    e.m_isHandled = true;
}


void Application::onKeyPress(KeyPressEvent & e)
{
    int code = e.getKeyCode();
    RP_EVENT_LOG(e, "Key #%d pressed, repeated %d", code, e.getRepeatState());

    if (code == GLFW_KEY_ESCAPE)
    {
        m_isRunning = false;
    }

    e.m_isHandled = true;
}


void Application::onKeyRelease(KeyReleaseEvent & e)
{
    RP_EVENT_LOG(e, "Key #%d released", e.getKeyCode());
    e.m_isHandled = true;
}


void Application::onMouseMove(MouseMoveEvent & e)
{
    RP_EVENT_LOG(e, "Mouse move at x:%lf y:%lf", e.getX(), e.getY());
    e.m_isHandled = true;
}


void Application::onMouseButtonPress(MouseButtonPressEvent & e)
{
    RP_EVENT_LOG(e, "Mouse button #%d pressed", e.getButton());
    e.m_isHandled = true;
}


void Application::onMouseButtonRelease(MouseButtonReleaseEvent & e)
{
    RP_EVENT_LOG(e, "Mouse button #%d released", e.getButton());
    e.m_isHandled = true;
}