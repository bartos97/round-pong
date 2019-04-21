#include "pch.h"
#include "Application.h"


// Declaration of static variable
Application* Application::m_instance;


Application::Application()
{
    RP_LOG("Application constructed.");
    m_window = std::unique_ptr<Window>(Window::create(1200, 1200));

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

    Player::generateModel();

    VertexBuffer playerVertexBuffer(unsigned int(Player::getVertices().size() * sizeof(float)), Player::getVertices().data());
    ElementBuffer playerElementBuffer(unsigned int(Player::getIndecies().size()), Player::getIndecies().data());
    BufferLayout playerLayout;
    playerLayout.add<float>(2);

    auto playerShaderPtr = std::make_shared<Shader>("src/Shaders/player.vert", "src/Shaders/player.frag");
    auto playerVertexArrayPtr = std::make_shared<VertexArray>(playerVertexBuffer, playerElementBuffer, playerLayout);
    m_userPlayer = std::unique_ptr<Player>(new Player(playerShaderPtr, playerVertexArrayPtr, 0.0));
    m_opponentPlayer = std::unique_ptr<Player>(new Player(playerShaderPtr, playerVertexArrayPtr, M_PI));

    RP_LOG("Entering the game loop");
    while (m_isRunning)
    {
        Renderer::clearScreen();

        m_userPlayer->render();
        m_opponentPlayer->render();

        m_window->onUpdate();
    }
    RP_LOG("Returned from game loop");
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

    const static double maxangle = M_PI / 2.0 - Player::modelSizeAngle / 2.0;

    // x and y with respect to center of a window
    double mouseY = m_window->m_data.height - e.getY() - m_window->m_data.windowCenterY;
    double mouseX = e.getX() - m_window->m_data.windowCenterX;
    double angle = (float)glm::atan(mouseY / mouseX);

    if (mouseX > 0.0 && angle < maxangle && angle > -maxangle)
    {
        m_userPlayer->setPosition(angle);
    }

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