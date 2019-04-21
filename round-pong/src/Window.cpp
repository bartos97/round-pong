#include "pch.h"
#include "GLFW/glfw3.h"
#include "Window.h"


// Declaration of static variable (nullptr by default)
Window* Window::m_instance;


Window::~Window()
{
    RP_LOG("Window destroyed.");
    glfwTerminate();
}


Window::Window(int width, int height, const std::string& title)
{
    m_window = nullptr;
    m_data.width = width;
    m_data.height = height;
    m_data.title = title;

    m_data.windowCenterX = width / 2.0;
    m_data.windowCenterY = height / 2.0;
    m_data.appSideLength = (width > height ? height : width);

    initGLFW();
    createWindow();
    initGlad();
    setCallbacks();
}


Window* Window::create(int width, int height, const std::string& title)
{
    if (!Window::m_instance)
    {
        Window::m_instance = new Window(width, height, title);
    }
    return Window::m_instance;
}


void Window::onUpdate() noexcept
{
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}


void Window::initGLFW()
{
    int tmpStatus = glfwInit();
    RP_ASSERT(tmpStatus, "GLFW initialization fail.");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // sets V-Sync
    glfwSwapInterval(1);    
}


void Window::initGlad()
{
    int tmpStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    RP_ASSERT(tmpStatus, "Glad initialization fail.");
	RP_LOG("OpenGL version: %s", glGetString(GL_VERSION));
}


void Window::createWindow()
{
    RP_LOG("Creating window: %dx%d %s", m_data.width, m_data.height, m_data.title.c_str());

    m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
    RP_ASSERT(m_window, "GLFW window creation fail.");

    glfwMakeContextCurrent(m_window);

    // associate window data (m_data) with GLFW window (m_window)
    glfwSetWindowUserPointer(m_window, &m_data);
}


void Window::setCallbacks()
{
    // Window close callback
    glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
        //retrieve data associated with window
        WindowData* dataPtr = (WindowData*)glfwGetWindowUserPointer(window);

        WindowCloseEvent event;
        dataPtr->callbackOnWindowClose(event);
    });

    // Window resize callback
    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
        WindowData* dataPtr = (WindowData*)glfwGetWindowUserPointer(window);
        dataPtr->width = width;
        dataPtr->height = height;
        dataPtr->windowCenterX = width / 2.0;
        dataPtr->windowCenterY = height / 2.0;

        WindowResizeEvent event(width, height);
        dataPtr->callbackOnWindowResize(event);
    });

    // Key input callback
    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        WindowData* dataPtr = (WindowData*)glfwGetWindowUserPointer(window);

        switch (action)
        {
            case GLFW_PRESS:
            {
                KeyPressEvent event(key, false);
                dataPtr->callbackOnKeyPress(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressEvent event(key, true);
                dataPtr->callbackOnKeyPress(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleaseEvent event(key);
                dataPtr->callbackOnKeyRelease(event);
                break;
            }
        }
    });

    // Mouse move callback
    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
        WindowData* dataPtr = (WindowData*)glfwGetWindowUserPointer(window);

        MouseMoveEvent event(xpos, ypos);
        dataPtr->callbackOnMouseMove(event);
    });

    // Mouse button press callback
    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
        WindowData* dataPtr = (WindowData*)glfwGetWindowUserPointer(window);

        switch (action)
        {
            case GLFW_PRESS:
            {
                MouseButtonPressEvent event(button);
                dataPtr->callbackOnMouseButtonPress(event);
                break;
            }
            case GLFW_RELEASE:
            {
                MouseButtonReleaseEvent event(button);
                dataPtr->callbackOnMouseButtonRelease(event);
                break;
            }
        }
    });
    
    // Frame buffer resize callback
    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
        WindowData* dataPtr = (WindowData*)glfwGetWindowUserPointer(window);
        int lowerLeftX, lowerLeftY;

        dataPtr->appSideLength = (width > height ? height : width);
        lowerLeftX = (width - dataPtr->appSideLength) / 2;
        lowerLeftY = (height - dataPtr->appSideLength) / 2;

        RP_LOG("Frame buffer resize: x = %d, y = %d", lowerLeftX, lowerLeftY);
        glViewport(lowerLeftX, lowerLeftY, dataPtr->appSideLength, dataPtr->appSideLength);
    });
}