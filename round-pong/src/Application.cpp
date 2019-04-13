#include "pch.h"
#include "Application.h"
#include "Renderer.h"
#include <cmath>


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

    const double radius = 0.9;
    const double radius2 = radius + (1.0 / 16.0);
    const unsigned int numOfSegments = 32;
    const double angle = M_PI / 6.0;
    const double angleInc = angle / static_cast<double>(numOfSegments);

    std::vector<float> arcVertices;
    arcVertices.reserve((numOfSegments + 1) * 2 * 2);

    std::vector<unsigned int> arcIndecies;
    arcIndecies.reserve(numOfSegments * 6);

    double startAngle = 0.0;
    float tmpX, tmpY;
    double tmpSin, tmpCos;

    for (unsigned int i = 0; i < numOfSegments + 1; i++)
    {
        tmpCos = std::cos(startAngle);
        tmpSin = std::sin(startAngle);

        tmpX = static_cast<float>(tmpCos * radius);
        tmpY = static_cast<float>(tmpSin * radius);
        arcVertices.push_back(tmpX);
        arcVertices.push_back(tmpY);

        tmpX = static_cast<float>(tmpCos * radius2);
        tmpY = static_cast<float>(tmpSin * radius2);
        arcVertices.push_back(tmpX);
        arcVertices.push_back(tmpY);        

        startAngle += angleInc;
    }

    for (unsigned int i = 0; i < numOfSegments * 2; i++)
    {
        arcIndecies.push_back(i);
        arcIndecies.push_back(i + 1);
        arcIndecies.push_back(i + 2);
    }

    Shader shader("src/Shaders/test.vert", "src/Shaders/test.frag");

    VertexBuffer vb(unsigned int(arcVertices.size() * sizeof(float)), arcVertices.data());
    ElementBuffer eb(unsigned int(arcIndecies.size()), arcIndecies.data());

    BufferLayout layout;
    layout.add<float>(2); //position

    VertexArray va(vb, eb, layout);
    Renderer renderer;

    va.unbind();
    vb.unbindAll();
    eb.unbindAll();

    const float INC = 1.0f / 256.0f;
    float i = INC;
    float r = i;

    while (m_isRunning)
    {
        renderer.clearScreen();

        if (r >= 1.0f) i = -INC;
        else if (r <= 0.0f) i = INC;
        r += i;

        shader.setUniform("uniformColor", r, 0.5f, 0.1f, 1.0f);
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