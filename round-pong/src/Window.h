#pragma once

/**
 * Singleton class for creating OS window
 */
class Window
{
public:
    static Window* create();
    void onUpdate()  noexcept;
    GLFWwindow* getWindow() const noexcept { return m_window; }
    ~Window();

private:
    Window(int width = 720,
           int height = 720,
           const std::string& title = "Round Pong");

    inline void initGLFW();
    inline void initGlad();
    inline void createWindow();
    inline void setCallbacks();

    static Window* m_instance;
    GLFWwindow* m_window;
    unsigned int m_width;
    unsigned int m_height;
    std::string m_title;
};

