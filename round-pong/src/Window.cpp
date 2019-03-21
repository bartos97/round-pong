#include "pch.h"
#include "GLFW/glfw3.h"
#include "Window.h"

//Initialization of static variable
Window* Window::instance = nullptr;

Window* Window::create() {
    if (!Window::instance) {
        Window::instance = new Window();
    }
    return Window::instance;
}

Window::Window(int width, int height, const std::string& title)
    : m_width(width), m_height(height), m_title(title) {
    this->init();
}

Window::~Window() {
    RP_LOG("Window destruction");
    glfwTerminate();
}

void Window::init() {
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

void Window::onUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

GLFWwindow * Window::getWindow() const {
    return m_window;
}
