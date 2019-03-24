#include "pch.h"
#include "GLFW/glfw3.h"
#include "Window.h"


// Declaration of static variable
Window* Window::m_instance;

Window* Window::create()
{
    if (!Window::m_instance)
    {
        Window::m_instance = new Window();
    }
    return Window::m_instance;
}

Window::Window(int width, int height, const std::string& title)
    : m_width(width), m_height(height), m_title(title)
{
    this->init();
}

Window::~Window()
{
    RP_LOG("Window destroyed.");
    glfwTerminate();
}

void Window::init()
{
    RP_LOG("Creating window: %dx%d %s", m_width, m_height, m_title.c_str());
    int tmpStatus;

    tmpStatus = glfwInit();
    RP_ASSERT(tmpStatus, "GLFW initialization fail.");

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    RP_ASSERT(m_window, "GLFW window creation fail.");
    glfwMakeContextCurrent(m_window);

    tmpStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    RP_ASSERT(tmpStatus, "Glad initialization fail.");

    // sets V-Sync
    glfwSwapInterval(1);

    // Lambda callback function on window resize
    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) -> void {
        glViewport(0, 0, width, height);
    });
}

void Window::onUpdate() noexcept
{
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}