#include "pch.h"
#include "GLFW/glfw3.h"
#include "Window.h"


// Declaration of static variable (nullptr by default)
Window* Window::m_instance;


Window* Window::create()
{
    if (!Window::m_instance)
    {
        Window::m_instance = new Window();
    }
    return Window::m_instance;
}


void Window::onUpdate() noexcept
{
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

Window::~Window()
{
    RP_LOG("Window destroyed.");
    glfwTerminate();
}


Window::Window(int width, int height, const std::string& title)
{
    m_data.width  = width;
    m_data.height = height;
    m_data.title  = title;

    initGLFW();
    createWindow();
    initGlad();
    setCallbacks();
}


void Window::initGLFW()
{
    int tmpStatus = glfwInit();
    RP_ASSERT(tmpStatus, "GLFW initialization fail.");

    // sets V-Sync
    glfwSwapInterval(1);    
}


void Window::initGlad()
{
    int tmpStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    RP_ASSERT(tmpStatus, "Glad initialization fail.");
}


void Window::createWindow()
{
    RP_LOG("Creating window: %dx%d %s", m_data.width, m_data.height, m_data.title.c_str());

    m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
    RP_ASSERT(m_window, "GLFW window creation fail.");

    glfwMakeContextCurrent(m_window);

    // associate window data with GLFW window
    glfwSetWindowUserPointer(m_window, &m_data);
}


void Window::setCallbacks()
{
    // Lambda callback function on window resize event
    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) -> void {
        glViewport(0, 0, width, height);
    });
}