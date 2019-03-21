#pragma once

/**
 * Singleton class for creating OS window
 */
class Window {
public:
    static Window* create();
    ~Window();

    void onUpdate();
    GLFWwindow* getWindow() const;

private:
    static Window*  instance;
    unsigned int    m_width;
    unsigned int    m_height;
    std::string     m_title;
    GLFWwindow*     m_window;
        
    Window( int width = 720,
            int height = 720,
            const std::string& title = "Round Pong");
    void init();

    //Singleton protection stuff
public:
    Window(const Window&) = delete;
    void operator=(const Window&) = delete;
};

