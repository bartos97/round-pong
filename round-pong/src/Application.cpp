#include "pch.h"
#include "Window.h"

int main() {
    auto window = Window::create();

    while (!glfwWindowShouldClose(window->getWindow())) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        window->onUpdate();
    }

    delete window;
    return 0;
}