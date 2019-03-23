#pragma once

/**
 * Singleton class for creating OS window
 */
class Window {
public:
    ~Window();
    static Window* create();
    void onUpdate()  noexcept;
    inline GLFWwindow* getWindow() const noexcept { return m_window; }

private:
    Window( int width = 720,
            int height = 720,
            const std::string& title = "Round Pong");

    void init();

    static Window* m_instance;
    GLFWwindow* m_window;
    unsigned int m_width;
    unsigned int m_height;
    std::string m_title;
};

