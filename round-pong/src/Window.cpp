#include "pch.h"
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
    //TODO: GLFW window terminate etc.
}

void Window::init() {
    RP_LOG("Creating window: %dx%d %s", m_width, m_height, m_title.c_str());
    //TODO: add GLFW window creation etc.
}